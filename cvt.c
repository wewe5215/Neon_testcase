#include "print_output.h"

static const struct {
    float32_t a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF, INT32_C(           0) },
      { HEDLEY_STATIC_CAST(float32_t, INT32_MAX) + SIMDE_FLOAT32_C(1000.0), INT32_MAX },
      { HEDLEY_STATIC_CAST(float32_t, INT32_MIN) - SIMDE_FLOAT32_C(1000.0), INT32_MIN },
    #endif
    { SIMDE_FLOAT32_C(   550.19), INT32_C(         550) },
    { SIMDE_FLOAT32_C(   -14.71), -INT32_C(          14) },
    { SIMDE_FLOAT32_C(   735.91), INT32_C(         735) },
    { SIMDE_FLOAT32_C(   355.60), INT32_C(         355) },
    { SIMDE_FLOAT32_C(  -850.41), -INT32_C(         850) },
    { SIMDE_FLOAT32_C(  -934.68), -INT32_C(         934) },
    { SIMDE_FLOAT32_C(  -125.28), -INT32_C(         125) },
    { SIMDE_FLOAT32_C(   784.80), INT32_C(         784) }
  };


  void f0(){

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      float32_t a = test_vec[i].a;
      int32_t r = vcvts_s32_f32(a);
      print_int32(r);
    }
    sprintf(buffer, "\n\n");
    puts_uart0(buffer);
    return;
  }
  
  void f1(){

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      float32_t a = test_vec[i].a;
      int32_t r = vcvtns_s32_f32(a);
      print_int32(r);
    }
    sprintf(buffer, "\n\n");
    puts_uart0(buffer);
    return;
  }

  void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      float32_t a = test_vec[i].a;
      int32_t r = vcvtas_s32_f32(a);
      print_int32(r);
      
    }
    
    return;
  }

  int main(){

    f0();
    f1();
    f2();
    return 0;
  }