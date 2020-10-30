#ifndef DHT_U_H
#define DHT_U_H

typedef struct {
  int32_t version;   /**< must be sizeof(struct sensors_event_t) */
  int32_t sensor_id; /**< unique sensor identifier */
  int32_t type;      /**< sensor type */
  int32_t reserved0; /**< reserved */
  int32_t timestamp; /**< time is in milliseconds */
  union {
    float data[4];              ///< Raw data
    sensors_vec_t acceleration; /**< acceleration values are in meter per second
                                   per second (m/s^2) */
    sensors_vec_t
        magnetic; /**< magnetic vector values are in micro-Tesla (uT) */
    sensors_vec_t orientation; /**< orientation values are in degrees */
    sensors_vec_t gyro;        /**< gyroscope values are in rad/s */
    float temperature; /**< temperature is in degrees centigrade (Celsius) */
    float distance;    /**< distance in centimeters */
    float light;       /**< light in SI lux units */
    float pressure;    /**< pressure in hectopascal (hPa) */
    float relative_humidity; /**< relative humidity in percent */
    float current;           /**< current in milliamps (mA) */
    float voltage;           /**< voltage in volts (V) */
    sensors_color_t color;   /**< color in RGB component values */
  };                         ///< Union for the wide ranges of data we can carry
} sensors_event_t;

class DHT_Unified 
{
  public :
    DHT_Unified(float initial_temp);
    float temp;
    
    class Temperature {
      public:
        Temperature(DHT_Unified *parent, int32_t id);
        bool getEvent(sensors_event_t *event);

      private:
        DHT_Unified *_parent;
      };
};

DHT_Unified::DHT_Unified(float initial_temp)
{
  temp = initial_temp
}

DHT_Unified::Temperature::Temperature(DHT_Unified *parent, int32_t id)
    : _parent(parent), _id(id) {}

bool DHT_Unified::Temperature::getEvent(sensors_event_t *event) {
  event->temperature = temp;

  return true;
}

#endif
