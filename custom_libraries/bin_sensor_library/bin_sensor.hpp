#ifndef BIN_SENSOR_H
#define BIN_SENSOR_H

#include <DHT_U.h>

// library interface description
class BinSensor {
  // user-accessible "public" interface
  public:
    BinSensor(float max_increase);
    float check_sensor(DHT_Unified sensor);
    float get_temp(DHT_Unified sensor);
    

  // library-accessible "private" interface
  private:
    float temp;
    float limit;
};

BinSensor::BinSensor(float max_increase)
{
  limit = max_increase;
  temp = 0.0;
}

float BinSensor::check_sensor(DHT_Unified sensor)
{
  float new_temp = get_temp(sensor);
  if (new_temp < -80.0)
  {
    return -1.0;
  }
  else if (temp > new_temp)
  {
    // temperature has not decreased
    return 0.0;
  }
  else 
  {
    // temperature has increased
    return new_temp - temp;
  }
}

float BinSensor::get_temp(DHT_Unified sensor)
{
  sensors_event_t new_event;
  
  float temperature;
  
  int count = 0;

  sensor.temperature().getEvent(&new_event);

  temperature = new_event.temperature;
  
  while (isnan(temperature) != true && count < 5)
  {
    delay(5000);
    sensor.temperature().getEvent(&new_event);

    temperature = new_event.temperature;
    
    count = count + 1;
  }
  
  if (count == 5)
  {
    // signals the sensor failed
    return -100.0;
  }
  else
  {
    return temperature;
  }
}

#endif