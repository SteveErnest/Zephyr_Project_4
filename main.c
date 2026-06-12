#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* Use Zephyr's built-in standard led0 alias */
#define LED_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    /* Verify the GPIO port is initialized and ready */
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    /* Configure the pin as an active output */
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
      gpio_pin_set_dt(&led, 1);
      k_msleep(100);
      gpio_pin_set_dt(&led, 0);
      k_msleep(100);
      gpio_pin_set_dt(&led, 1);
      k_msleep(100);
      gpio_pin_set_dt(&led, 0);
      k_msleep(100);
      k_msleep(700);
    }

    return 0;
}
