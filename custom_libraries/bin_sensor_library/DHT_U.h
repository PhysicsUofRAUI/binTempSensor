#ifndef DHT_U_H
#define DHT_U_H

void delay(int seconds) {
  int mysecs = seconds;
  return;
}

typedef struct {
  int32_t version;   /**< must be sizeof(struct sensors_event_t) */
  int32_t sensor_id; /**< unique sensor identifier */
  int32_t type;      /**< sensor type */
  int32_t reserved0; /**< reserved */
  int32_t timestamp; /**< time is in milliseconds */
  union {
    float data[4];              ///< Raw data
    float temperature; /**< temperature is in degrees centigrade (Celsius) */
    float distance;    /**< distance in centimeters */
    float light;       /**< light in SI lux units */
    float pressure;    /**< pressure in hectopascal (hPa) */
    float relative_humidity; /**< relative humidity in percent */
    float current;           /**< current in milliamps (mA) */
    float voltage;           /**< voltage in volts (V) */
  };                         ///< Union for the wide ranges of data we can carry
} sensors_event_t;

class DHT_Unified 
{
  public :
    DHT_Unified(float initial_temp);
    float temp;

    class Temperature {
      public:
        Temperature(DHT_Unified *parent);
        bool getEvent(sensors_event_t *event);
      private:
        DHT_Unified *_parent;
      };
      
      Temperature temperature() { return _temp; }
      
    private:
      Temperature _temp;
};

DHT_Unified::DHT_Unified(float initial_temp)
    : temp(initial_temp), _temp(this) {}


DHT_Unified::Temperature::Temperature(DHT_Unified *parent)
    : _parent(parent) {}

bool DHT_Unified::Temperature::getEvent(sensors_event_t *event) {
  event->temperature = _parent->temp;

  return true;
}

#endif
