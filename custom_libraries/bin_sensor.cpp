#include "catch.hpp"
#include "bin_sensor_library/bin_sensor.hpp"

TEST_CASE("Test positive values using get_temp", "[bin-sensor]") {
    DHT_Unified sensor(0.7);
    
    BinSensor bin_sensor(0.5);
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)0.7));
    
    sensor.temp = 1.8;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)1.8));
    
    sensor.temp = 5.4;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)5.4));
    
    sensor.temp = 20.5;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)20.5));
    
    sensor.temp = 100.5;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)100.5));
}

TEST_CASE("Test negative values using get_temp", "[bin-sensor]") {
    DHT_Unified sensor(-0.7);
    
    BinSensor bin_sensor(0.5);
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-0.7));
    
    sensor.temp = -1.8;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-1.8));
    
    sensor.temp = -5.4;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-5.4));
    
    sensor.temp = -20.5;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-20.5));
    
    sensor.temp = -100.5;
    
    REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-100.5));
}

TEST_CASE("Test special values using get_temp", "[bin-sensor]") {
  DHT_Unified sensor(0.0);
  
  BinSensor bin_sensor(0.5);
  
  REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)0.0));
  
  sensor.temp = -0.0;
  
  REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-0.0));
  
  sensor.temp = 0.0 / 0.0;
  
  REQUIRE(bin_sensor.get_temp(sensor) == Approx((float)-100.0));
}

/*
Testing the check_sensor function
*/
TEST_CASE("Test positive values using check_sensor", "[bin-sensor]") {
    DHT_Unified sensor(0.7);
    
    BinSensor bin_sensor(0.5);
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.7));
    
    sensor.temp = 0.5;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
    
    sensor.temp = 0.9;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.4));
    
    sensor.temp = 1.8;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.9));
    
    sensor.temp = 5.4;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)3.6));
    
    sensor.temp = 20.5;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)15.1));
    
    sensor.temp = 100.5;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)80.0));
}

TEST_CASE("Test negative values using check_sensor", "[bin-sensor]") {
    DHT_Unified sensor(-0.7);
    
    BinSensor bin_sensor(0.5);
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
    
    sensor.temp = -1.8;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
    
    sensor.temp = -5.4;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
    
    sensor.temp = -20.5;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
    
    sensor.temp = -100.5;
    
    REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)-1.0));
}

TEST_CASE("Test special values using check_sensor", "[bin-sensor]") {
  DHT_Unified sensor(0.0);
  
  BinSensor bin_sensor(0.5);
  
  REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
  
  sensor.temp = -0.0;
  
  REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)0.0));
  
  sensor.temp = 0.0 / 0.0;
  
  REQUIRE(bin_sensor.check_sensor(sensor) == Approx((float)-1.0));
}
