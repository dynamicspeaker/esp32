#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    static const i2s_config_t i2s_config = {
        .mode = (i2s_mode_t) (I2S_MODE_SLAVE | I2S_MODE_TX),
        .sample_rate = 44100, // corrected by info from bluetooth
        .bits_per_sample = (i2s_bits_per_sample_t) I2S_BITS_PER_SAMPLE_32BIT, /* the DAC module will only take the 8bits from MSB */
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t) I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = 0, // default interrupt priority
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = true

    };
    i2s_pin_config_t my_pin_config = {
        .bck_io_num = 26,
        .ws_io_num = 25,
        .data_out_num = 21,
        .data_in_num = I2S_PIN_NO_CHANGE
    };
    a2dp_sink.set_i2s_config(i2s_config);
    a2dp_sink.set_pin_config(my_pin_config);
    a2dp_sink.start("MyMusic");

}

void loop() {
}