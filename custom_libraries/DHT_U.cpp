#include "catch.hpp"
#include "bin_sensor_library/DHT_U.h"


TEST_CASE("Test positive values", "[DHT-U]") {
    DHT_Unified sensor(0.7);
    
    sensors_event_t new_event;
    
    sensor.temperature().getEvent(&new_event);
    
    REQUIRE(new_event.temperature == Approx((float)0.7));
    
    sensor.temp = 1.8;
    
    sensor.temperature().getEvent(&new_event);
    
    REQUIRE(new_event.temperature == Approx((float)1.8));
    
    sensor.temp = 5.4;
    
    sensor.temperature().getEvent(&new_event);
    
    REQUIRE(new_event.temperature == Approx((float)5.4));
    
    sensor.temp = 100.5;
    
    sensor.temperature().getEvent(&new_event);
    
    REQUIRE(new_event.temperature == Approx((float)100.5));
}

TEST_CASE("Test negative values", "[DHT-U]") {
  DHT_Unified sensor(-0.7);
  
  sensors_event_t new_event;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)-0.7));
  
  sensor.temp = -1.8;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)-1.8));
  
  sensor.temp = -5.4;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)-5.4));
  
  sensor.temp = -100.5;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)-100.5));
}

TEST_CASE("Test special values", "[DHT-U]") {
  DHT_Unified sensor(0.0);
  
  sensors_event_t new_event;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)0.0));
  
  sensor.temp = -0.0;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(new_event.temperature == Approx((float)-0.0));
  
  sensor.temp = 0.0 / 0.0;
  
  sensor.temperature().getEvent(&new_event);
  
  REQUIRE(std::isnan(new_event.temperature) == true);
}


