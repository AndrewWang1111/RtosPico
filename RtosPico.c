#include <stdio.h>
#include <hardware/gpio.h>
#include <FreeRTOS.h>
#include <timers.h>
#include <task.h>
#include "pico/stdlib.h"


#define ledApp1 2
#define ledApp2 4
static void app1(void*);
static void app2(void*);

int main()
{
    stdio_init_all();
    xTaskCreate(app1,"app1",1024,NULL,1,NULL);
    xTaskCreate(app2,"app1",1024,NULL,1,NULL);
    vTaskStartScheduler();
    while(1);
    return 0;
}


void app1(void* vp)
{
    gpio_init(ledApp1);
    gpio_set_dir(ledApp1,GPIO_OUT);
    while(1)
    {
        gpio_put(ledApp1,0);
        vTaskDelay(1000);
        gpio_put(ledApp1,1);
        vTaskDelay(1000);
    }
}

void app2(void* vp)
{
    gpio_init(ledApp2);
    gpio_set_dir(ledApp2,GPIO_OUT);
    while(1)
    {
        gpio_put(ledApp2,0);
        vTaskDelay(500);
        gpio_put(ledApp2,1);
        vTaskDelay(500);
    }
}