LED_Blink(LED1_PIN, 3, 200);
            xEventGroupSetBits(xEventGroup, BIT_TASK1_DONE);
        }
    }
}

/* ---- Task2 ---- */
void vTask2(void *pvParameters)
{
    EventBits_t bits;
    for (;;)
    {
        bits = xEventGroupWaitBits(xEventGroup, BIT_TASK2_TRIGGER,
                                   pdTRUE, pdFALSE, portMAX_DELAY);
        if (bits & BIT_TASK2_TRIGGER)
        {
            LED_Blink(LED2_PIN, 5, 150);
            xEventGroupSetBits(xEventGroup, BIT_TASK2_DONE);
        }
    }
}

/* ---- Task3 ---- */
void vTask3(void *pvParameters)
{
    EventBits_t bits;
    for (;;)
    {
        bits = xEventGroupWaitBits(xEventGroup, BIT_TASK3_TRIGGER,
                                   pdTRUE, pdFALSE, portMAX_DELAY);
        if (bits & BIT_TASK3_TRIGGER)
        {
            LED_On(LED3_PIN);                     
            vTaskDelay(pdMS_TO_TICKS(1000));       
            LED_Off(LED3_PIN);                    
            xEventGroupSetBits(xEventGroup, BIT_TASK3_DONE);
        }
    }
}
