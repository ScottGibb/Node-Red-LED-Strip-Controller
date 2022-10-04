/**
 * @file LEDDriver.h
 * @author Scott Gibb (smgibb@yahoo.com)
 * @brief LED Driver Header file
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__


// Library Includes
#include <stdint.h>
#include <Arduino.h>

//LED PWM Constants
const uint8_t MAX_PWM =255;
const uint8_t MIN_PWM =0;


//Constants
const uint8_t NUM_LEDS =3;
const uint8_t LED_COLOUR_ENUM_LEN =NUM_LEDS;

/**
 * @brief LED Colour ENUM used to define the hardware RGB LED
 * 
 */
enum LED_COLOUR{
  RED_ =0,
  GREEN_ =1,
  BLUE_ = 2
};


/**
 * @brief LED Driver Class Declaration
 * Responsible for outlining the low level functionality of the RGB LED and providing an abstracted interface for control
 * 
 */
class LEDDriver{
  public:
    LEDDriver(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
    ~LEDDriver();
    void setPWM(enum LED_COLOUR colour, uint8_t pwm);
    void setPWMS(uint8_t* pwms);
    uint8_t getPWM(enum LED_COLOUR colour);

  private:
  uint8_t pwm[3] = {0};
  uint8_t ledPins[LED_COLOUR_ENUM_LEN] ={0};

};


#endif