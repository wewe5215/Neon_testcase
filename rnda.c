#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
#define simde_float16 float16_t
#define simde_float32 float
#define simde_float64 double
#define SIMDE_FLOAT16_VALUE(value)  HEDLEY_STATIC_CAST(float16_t, value)
static const struct {
    simde_float16 a[4];
    simde_float16 r[4];
  } test_vec_f16[] = {
    
    { { SIMDE_FLOAT16_VALUE(   402.50), SIMDE_FLOAT16_VALUE(  -327.25), SIMDE_FLOAT16_VALUE(   405.25), SIMDE_FLOAT16_VALUE(  -207.75) },
    },
    { { SIMDE_FLOAT16_VALUE(  -248.62), SIMDE_FLOAT16_VALUE(   342.00), SIMDE_FLOAT16_VALUE(  -816.50), SIMDE_FLOAT16_VALUE(   -39.50) },
    },
    { { SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   -18.20), SIMDE_FLOAT16_VALUE(   855.00), SIMDE_FLOAT16_VALUE(   748.50) },
    },
    { { SIMDE_FLOAT16_VALUE(   854.00), SIMDE_FLOAT16_VALUE(   763.50), SIMDE_FLOAT16_VALUE(   -35.88), SIMDE_FLOAT16_VALUE(   784.50) },
    },
    { { SIMDE_FLOAT16_VALUE(  -488.25), SIMDE_FLOAT16_VALUE(   -26.98), SIMDE_FLOAT16_VALUE(  -745.50), SIMDE_FLOAT16_VALUE(   482.00) },
    },
    { { SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(  -949.00), SIMDE_FLOAT16_VALUE(   895.50), SIMDE_FLOAT16_VALUE(   155.25) },
    },
    { { SIMDE_FLOAT16_VALUE(   587.50), SIMDE_FLOAT16_VALUE(  -593.50), SIMDE_FLOAT16_VALUE(  -799.00), SIMDE_FLOAT16_VALUE(  -267.00) },
    },
    { { SIMDE_FLOAT16_VALUE(  -415.25), SIMDE_FLOAT16_VALUE(  -279.00), SIMDE_FLOAT16_VALUE(  -736.00), SIMDE_FLOAT16_VALUE(  -355.25) },
    }
    
  };
static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec_f32[] = {
    
      { { SIMDE_FLOAT32_C(    -5.92), SIMDE_FLOAT32_C(   639.44) },
      },
      { { SIMDE_FLOAT32_C(   204.12), SIMDE_FLOAT32_C(   -25.44) },
      },
      { { SIMDE_FLOAT32_C(   696.96), SIMDE_FLOAT32_C(   355.18) },
      },
      { { SIMDE_FLOAT32_C(  -985.63), SIMDE_FLOAT32_C(   842.52) },
      },
      { { SIMDE_FLOAT32_C(  -506.88), SIMDE_FLOAT32_C(  -550.99) },
      },
      { { SIMDE_FLOAT32_C(   121.43), SIMDE_FLOAT32_C(   844.38) },
      },
      { { SIMDE_FLOAT32_C(  -673.27), SIMDE_FLOAT32_C(  -707.29) },
      },
      { { SIMDE_FLOAT32_C(   135.56), SIMDE_FLOAT32_C(   290.00) },
      }
   
  };

static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec_f64[] = {
    
    { { SIMDE_FLOAT64_C(   450.02) },
    },
    { { SIMDE_FLOAT64_C(   185.04) },
    },
    { { SIMDE_FLOAT64_C(   116.78) },
    },
    { { SIMDE_FLOAT64_C(  -398.58) },
    },
    { { SIMDE_FLOAT64_C(  -381.80) },
    },
    { { SIMDE_FLOAT64_C(  -913.23) },
    },
    { { SIMDE_FLOAT64_C(    94.63) },
    },
    { { SIMDE_FLOAT64_C(    50.38) },
    }
  };

static const struct {
    simde_float16 a[8];
    simde_float16 r[8];
  } test_vec_f16q[] = {
    { { SIMDE_FLOAT16_VALUE(   131.50), SIMDE_FLOAT16_VALUE(  -289.00), SIMDE_FLOAT16_VALUE(  -100.88), SIMDE_FLOAT16_VALUE(  -881.00),
        SIMDE_FLOAT16_VALUE(  -149.50), SIMDE_FLOAT16_VALUE(   558.00), SIMDE_FLOAT16_VALUE(   800.50), SIMDE_FLOAT16_VALUE(  -454.00) },
    },
    { { SIMDE_FLOAT16_VALUE(   400.00), SIMDE_FLOAT16_VALUE(  -230.38), SIMDE_FLOAT16_VALUE(  -477.50), SIMDE_FLOAT16_VALUE(   924.00),
        SIMDE_FLOAT16_VALUE(   -85.00), SIMDE_FLOAT16_VALUE(   -74.06), SIMDE_FLOAT16_VALUE(  -465.50), SIMDE_FLOAT16_VALUE(  -573.50) },
    },
    { { SIMDE_FLOAT16_VALUE(    19.80), SIMDE_FLOAT16_VALUE(  -353.25), SIMDE_FLOAT16_VALUE(  -369.25), SIMDE_FLOAT16_VALUE(   870.50),
        SIMDE_FLOAT16_VALUE(  -795.50), SIMDE_FLOAT16_VALUE(  -569.00), SIMDE_FLOAT16_VALUE(  -584.00), SIMDE_FLOAT16_VALUE(   432.00) },
    },
    { { SIMDE_FLOAT16_VALUE(  -862.00), SIMDE_FLOAT16_VALUE(  -627.00), SIMDE_FLOAT16_VALUE(   848.50), SIMDE_FLOAT16_VALUE(    52.91),
        SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(  -617.00), SIMDE_FLOAT16_VALUE(   479.50), SIMDE_FLOAT16_VALUE(   445.25) },
    },
    { { SIMDE_FLOAT16_VALUE(  -586.50), SIMDE_FLOAT16_VALUE(  -229.00), SIMDE_FLOAT16_VALUE(   -47.53), SIMDE_FLOAT16_VALUE(  -382.00),
        SIMDE_FLOAT16_VALUE(   202.12), SIMDE_FLOAT16_VALUE(   368.75), SIMDE_FLOAT16_VALUE(  -950.00), SIMDE_FLOAT16_VALUE(   602.00) },
    },
    { { SIMDE_FLOAT16_VALUE(  -226.62), SIMDE_FLOAT16_VALUE(   911.50), SIMDE_FLOAT16_VALUE(  -631.50), SIMDE_FLOAT16_VALUE(  -927.50),
        SIMDE_FLOAT16_VALUE(  -705.50), SIMDE_FLOAT16_VALUE(   848.00), SIMDE_FLOAT16_VALUE(   517.50), SIMDE_FLOAT16_VALUE(  -456.50) },
    },
    { { SIMDE_FLOAT16_VALUE(    83.62), SIMDE_FLOAT16_VALUE(   698.50), SIMDE_FLOAT16_VALUE(  -665.00), SIMDE_FLOAT16_VALUE(  -714.50),
        SIMDE_FLOAT16_VALUE(    67.25), SIMDE_FLOAT16_VALUE(  -615.00), SIMDE_FLOAT16_VALUE(   888.00), SIMDE_FLOAT16_VALUE(  -319.25) },
    },
    { { SIMDE_FLOAT16_VALUE(  -206.38), SIMDE_FLOAT16_VALUE(    55.94), SIMDE_FLOAT16_VALUE(   684.00), SIMDE_FLOAT16_VALUE(    88.25),
        SIMDE_FLOAT16_VALUE(   -96.19), SIMDE_FLOAT16_VALUE(   201.50), SIMDE_FLOAT16_VALUE(   631.50), SIMDE_FLOAT16_VALUE(  -494.75) },
    }
  };

static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec_f32q[] = {
    { { SIMDE_FLOAT32_C(  -899.53), SIMDE_FLOAT32_C(  -409.17), SIMDE_FLOAT32_C(   286.63), SIMDE_FLOAT32_C(  -561.31) },
    },
    { { SIMDE_FLOAT32_C(  -975.35), SIMDE_FLOAT32_C(  -880.60), SIMDE_FLOAT32_C(  -731.38), SIMDE_FLOAT32_C(   126.22) },
    },
    { { SIMDE_FLOAT32_C(   270.51), SIMDE_FLOAT32_C(   661.53), SIMDE_FLOAT32_C(  -889.64), SIMDE_FLOAT32_C(   285.52) },
    },
    { { SIMDE_FLOAT32_C(   856.65), SIMDE_FLOAT32_C(   452.24), SIMDE_FLOAT32_C(  -546.81), SIMDE_FLOAT32_C(   973.11) },
    },
    { { SIMDE_FLOAT32_C(  -877.53), SIMDE_FLOAT32_C(   688.37), SIMDE_FLOAT32_C(   537.77), SIMDE_FLOAT32_C(  -595.94) },
    },
    { { SIMDE_FLOAT32_C(  -622.17), SIMDE_FLOAT32_C(   617.16), SIMDE_FLOAT32_C(  -990.62), SIMDE_FLOAT32_C(   362.79) },
    },
    { { SIMDE_FLOAT32_C(  -175.78), SIMDE_FLOAT32_C(   282.66), SIMDE_FLOAT32_C(   728.44), SIMDE_FLOAT32_C(   828.62) },
    },
    { { SIMDE_FLOAT32_C(  -559.92), SIMDE_FLOAT32_C(   503.07), SIMDE_FLOAT32_C(    51.67), SIMDE_FLOAT32_C(  -805.60) },
    }
  };

static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec_f64q[] = {
    { { SIMDE_FLOAT64_C(  -674.36), SIMDE_FLOAT64_C(    69.20) },
    },
    { { SIMDE_FLOAT64_C(  -587.76), SIMDE_FLOAT64_C(  -356.34) },
    },
    { { SIMDE_FLOAT64_C(    14.67), SIMDE_FLOAT64_C(  -132.81) },
    },
    { { SIMDE_FLOAT64_C(   518.18), SIMDE_FLOAT64_C(   689.73) },
    },
    { { SIMDE_FLOAT64_C(   524.28), SIMDE_FLOAT64_C(   617.96) },
    },
    { { SIMDE_FLOAT64_C(  -525.15), SIMDE_FLOAT64_C(  -817.30) },
    },
    { { SIMDE_FLOAT64_C(   396.81), SIMDE_FLOAT64_C(  -908.04) },
    },
    { { SIMDE_FLOAT64_C(   806.16), SIMDE_FLOAT64_C(  -693.25) },
    }
  };

int main(){

    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    return 0;
}

void f1(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16) / sizeof(test_vec_f16[0])) ; i++) {
        float16x4_t a = vld1_f16(test_vec_f16[i].a);
        float16x4_t rst = vrnda_f16(a);
        print_float16x4(rst);
    }
}

void f2(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f32) / sizeof(test_vec_f32[0])) ; i++) {
        float32x2_t a = vld1_f32(test_vec_f32[i].a);
        float32x2_t rst = vrnda_f32(a);
        print_float32x2(rst);
    }
}



void f3(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64) / sizeof(test_vec_f64[0])) ; i++) {
        float64x1_t a = vld1_f64(test_vec_f64[i].a);
        float64x1_t rst = vrnda_f64(a);
        print_float64x1(rst);

    }
}

void f4(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16q) / sizeof(test_vec_f16q[0])) ; i++) {
        float16x8_t a = vld1q_f16(test_vec_f16q[i].a);
        float16x8_t rst = vrndaq_f16(a);
        print_float16x8(rst);
    }
}

void f5(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f32q) / sizeof(test_vec_f32q[0])) ; i++) {
        float32x4_t a = vld1q_f32(test_vec_f32q[i].a);
        float32x4_t rst = vrndaq_f32(a);
        print_float32x4(rst);
    }
}

void f6(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64q) / sizeof(test_vec_f64q[0])) ; i++) {
        float64x2_t a = vld1q_f64(test_vec_f64q[i].a);
        float64x2_t rst = vrndaq_f64(a);
        print_float64x2(rst);
    }
}


