//This code was made with the help of ai but i understand and write down everything myself.
#include <driver/i2s.h>//this lest my esp32 to cnnect over my mic
#define I2S_PORT I2S_NUM_0
#define I2S_WS 4
#define I2S_SCK 5
#define I2S_SD  6

void setup() {
 Serial.begin(115200);
 i2s_confiig_t config ={
  .mode=(i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
  .sample_rate = 16000,
  .bits_per_channel_format=I2S_BITS_PER_SAMPLE_32BIT,
  .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
  .communication_format = I2S_COMM_FORMAT_STAND_I2S,
  .intr_alloc_flags = 0,
  .dma_buf_count = 8,
  .dma_buf_len = 256,
  .use_apll = false
 };
 i2s_pin_config_t ppins={
  .bck_io_num=I2S_SCK,
  .ws_io_num = I2S_WS,
  .data_out_num = I2S_PIN_NO_CHANGE,
  .data_in_num = I2S_SD
 };
 Serial.println("Microphone ready");

}

void loop() {
  // put your main code here, to run repeatedly:
  int32_t samples[256]
  size_t bytesRead = 0;
   i2s_read(I2S_PORT, samples, sizeof(samples),
           &bytesRead, portMAX_DELAY);

  int32_t peak = 0;

  for (int i = 0; i < bytesRead / 4; i++) {
    int32_t value = abs(samples[i] >> 14);
    if (value > peak) peak = value;
  }

  Serial.println(peak);
}
 
}
