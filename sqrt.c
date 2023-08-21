#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();

static const struct {
    float32_t a[2];
    float32_t r[2];
  } test_vec_f32[] = {
    { { SIMDE_FLOAT32_C(     3.47), SIMDE_FLOAT32_C(     2.63) },
    },
    { { SIMDE_FLOAT32_C(     5.66), SIMDE_FLOAT32_C(     2.23) },
    },
    { { SIMDE_FLOAT32_C(    -3.31), SIMDE_FLOAT32_C(     4.90) },
    },
    { { SIMDE_FLOAT32_C(     1.51), SIMDE_FLOAT32_C(     9.14) },
    },
    { { SIMDE_FLOAT32_C(    -4.52), SIMDE_FLOAT32_C(    -7.37) },
    },
    { { SIMDE_FLOAT32_C(    -3.42), SIMDE_FLOAT32_C(     6.84) },
    },
    { { SIMDE_FLOAT32_C(    -9.38), SIMDE_FLOAT32_C(     7.14) },
    },
    { { SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(     6.16) },
    }
  };


  static const struct {
    float32_t a[4];
    float32_t r[4];
  } test_vec_f32q[] = {
    { { SIMDE_FLOAT32_C(     6.70), SIMDE_FLOAT32_C(     1.28), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(     7.75) },
    },
    { { SIMDE_FLOAT32_C(     6.59), SIMDE_FLOAT32_C(     4.36), SIMDE_FLOAT32_C(    -9.49), SIMDE_FLOAT32_C(     0.20) },
    },
    { { SIMDE_FLOAT32_C(     4.48), SIMDE_FLOAT32_C(    -6.56), SIMDE_FLOAT32_C(     8.71), SIMDE_FLOAT32_C(     0.39) },
    },
    { { SIMDE_FLOAT32_C(    -7.73), SIMDE_FLOAT32_C(    -5.31), SIMDE_FLOAT32_C(    -1.15), SIMDE_FLOAT32_C(     9.33) },
    },
    { { SIMDE_FLOAT32_C(    -2.28), SIMDE_FLOAT32_C(     1.61), SIMDE_FLOAT32_C(     9.36), SIMDE_FLOAT32_C(    -9.34) },
    },
    { { SIMDE_FLOAT32_C(     7.19), SIMDE_FLOAT32_C(    -6.35), SIMDE_FLOAT32_C(    -4.79), SIMDE_FLOAT32_C(     3.30) },
    },
    { { SIMDE_FLOAT32_C(     4.92), SIMDE_FLOAT32_C(    -3.81), SIMDE_FLOAT32_C(    -7.38), SIMDE_FLOAT32_C(    -7.27) },
    },
    { { SIMDE_FLOAT32_C(    -1.88), SIMDE_FLOAT32_C(     1.47), SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -8.96) }
    }
  };

static const struct {
    float64_t a[1];
    float64_t r[1];
  } test_vec_f64[] = {
    { { SIMDE_FLOAT64_C(     4.45) },
    },
    { { SIMDE_FLOAT64_C(     0.97) },
    },
    { { SIMDE_FLOAT64_C(     5.03) },
    },
    { { SIMDE_FLOAT64_C(    -1.23) },
    },
    { { SIMDE_FLOAT64_C(     6.94) },
    },
    { { SIMDE_FLOAT64_C(    -5.77) },
    },
    { { SIMDE_FLOAT64_C(    -7.57) },
    },
    { { SIMDE_FLOAT64_C(    -8.47) },
    }
  };

  static const struct {
    float64_t a[2];
    float64_t r[2];
  } test_vec_f64q[] = {
    { { SIMDE_FLOAT64_C(     6.90), SIMDE_FLOAT64_C(     6.76) },
    },
    { { SIMDE_FLOAT64_C(    -7.88), SIMDE_FLOAT64_C(     9.25) },
    },
    { { SIMDE_FLOAT64_C(     9.75), SIMDE_FLOAT64_C(    -6.41) },
    },
    { { SIMDE_FLOAT64_C(    -6.35), SIMDE_FLOAT64_C(    -5.42) },
    },
    { { SIMDE_FLOAT64_C(    -1.94), SIMDE_FLOAT64_C(     0.22) },
    },
    { { SIMDE_FLOAT64_C(    -6.76), SIMDE_FLOAT64_C(    -4.07) },
    },
    { { SIMDE_FLOAT64_C(    -2.05), SIMDE_FLOAT64_C(     7.64) },
    },
    { { SIMDE_FLOAT64_C(    -5.53), SIMDE_FLOAT64_C(    -5.07) },
    }
  };


  static const struct {
    float16_t a;
    float16_t r;
  } test_vec_f16h[] = {
    { HEDLEY_STATIC_CAST(float16_t, 279.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 505.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 91.44),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 217.50),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 903.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, -717.50),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 45.19),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 148.88),
    
    }  
  };


  static const struct {
      float16_t a[4];
      float16_t r[4];
    } test_vec_f16[] = {
      { { HEDLEY_STATIC_CAST(float16_t, -228.12), HEDLEY_STATIC_CAST(float16_t, -98.75), HEDLEY_STATIC_CAST(float16_t, 350.00), HEDLEY_STATIC_CAST(float16_t, -598.00) }
      
      },
    { { HEDLEY_STATIC_CAST(float16_t, -136.50), HEDLEY_STATIC_CAST(float16_t, -721.00), HEDLEY_STATIC_CAST(float16_t, -692.00), HEDLEY_STATIC_CAST(float16_t, -858.00) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t,  -990.00), HEDLEY_STATIC_CAST(float16_t, 258.50), HEDLEY_STATIC_CAST(float16_t, 727.00), HEDLEY_STATIC_CAST(float16_t, -48.00) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t, 617.00), HEDLEY_STATIC_CAST(float16_t, -746.00), HEDLEY_STATIC_CAST(float16_t, -75.25), HEDLEY_STATIC_CAST(float16_t, -41.00) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t, -718.00), HEDLEY_STATIC_CAST(float16_t, -271.25), HEDLEY_STATIC_CAST(float16_t, -665.00), HEDLEY_STATIC_CAST(float16_t, 877.50) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t, -662.00), HEDLEY_STATIC_CAST(float16_t, -253.50), HEDLEY_STATIC_CAST(float16_t, 223.25), HEDLEY_STATIC_CAST(float16_t, -1405.00) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t, -1530.00), HEDLEY_STATIC_CAST(float16_t, -257.50), HEDLEY_STATIC_CAST(float16_t, -206.00), HEDLEY_STATIC_CAST(float16_t, 801.50) } 
    
    },
    { { HEDLEY_STATIC_CAST(float16_t, -594.00), HEDLEY_STATIC_CAST(float16_t, -1314.00), HEDLEY_STATIC_CAST(float16_t, -596.50), HEDLEY_STATIC_CAST(float16_t, 1568.00) } 
    
    }
    
    };

static const struct {
      float16_t a[8];
      float16_t r[8];
    } test_vec_f16q[] = {
      { { HEDLEY_STATIC_CAST(float16_t, 1125.00), HEDLEY_STATIC_CAST(float16_t,   1424.00), HEDLEY_STATIC_CAST(float16_t,    113.38), HEDLEY_STATIC_CAST(float16_t,    109.50),
        HEDLEY_STATIC_CAST(float16_t,   -27.50), HEDLEY_STATIC_CAST(float16_t,    142.50), HEDLEY_STATIC_CAST(float16_t,   -435.75), HEDLEY_STATIC_CAST(float16_t,    388.00) } 
      },
    { { HEDLEY_STATIC_CAST(float16_t,   -854.50), HEDLEY_STATIC_CAST(float16_t,    844.50), HEDLEY_STATIC_CAST(float16_t,  -1528.00), HEDLEY_STATIC_CAST(float16_t,    542.00),
        HEDLEY_STATIC_CAST(float16_t,    631.00), HEDLEY_STATIC_CAST(float16_t,   -426.00), HEDLEY_STATIC_CAST(float16_t,   1139.00), HEDLEY_STATIC_CAST(float16_t,    359.00) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,    918.50), HEDLEY_STATIC_CAST(float16_t,    -50.50), HEDLEY_STATIC_CAST(float16_t,    -25.00), HEDLEY_STATIC_CAST(float16_t,    892.00),
        HEDLEY_STATIC_CAST(float16_t,     91.88), HEDLEY_STATIC_CAST(float16_t,   -461.00), HEDLEY_STATIC_CAST(float16_t,   -720.00), HEDLEY_STATIC_CAST(float16_t,  -1230.00) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,    195.50), HEDLEY_STATIC_CAST(float16_t,    146.50), HEDLEY_STATIC_CAST(float16_t,   1512.00), HEDLEY_STATIC_CAST(float16_t,    826.00),
        HEDLEY_STATIC_CAST(float16_t,   -279.00), HEDLEY_STATIC_CAST(float16_t,    652.00), HEDLEY_STATIC_CAST(float16_t,   -814.50), HEDLEY_STATIC_CAST(float16_t,   -217.88) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,    833.00), HEDLEY_STATIC_CAST(float16_t,   1572.00), HEDLEY_STATIC_CAST(float16_t,     87.00), HEDLEY_STATIC_CAST(float16_t,  -1076.00),
        HEDLEY_STATIC_CAST(float16_t,   -889.50), HEDLEY_STATIC_CAST(float16_t,   1367.00), HEDLEY_STATIC_CAST(float16_t,   -306.00), HEDLEY_STATIC_CAST(float16_t,   -758.00) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,   -216.25), HEDLEY_STATIC_CAST(float16_t,  -1884.00), HEDLEY_STATIC_CAST(float16_t,    317.00), HEDLEY_STATIC_CAST(float16_t,   -495.25),
        HEDLEY_STATIC_CAST(float16_t,    767.50), HEDLEY_STATIC_CAST(float16_t,   1502.00), HEDLEY_STATIC_CAST(float16_t,   -713.00), HEDLEY_STATIC_CAST(float16_t,   -240.75) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,    659.50), HEDLEY_STATIC_CAST(float16_t,   -156.50), HEDLEY_STATIC_CAST(float16_t,  -1025.00), HEDLEY_STATIC_CAST(float16_t,   -229.50),
        HEDLEY_STATIC_CAST(float16_t,   1210.00), HEDLEY_STATIC_CAST(float16_t,    669.00), HEDLEY_STATIC_CAST(float16_t,   -988.00), HEDLEY_STATIC_CAST(float16_t,   -984.00) } 
    },
    { { HEDLEY_STATIC_CAST(float16_t,   -634.00), HEDLEY_STATIC_CAST(float16_t,   -283.75), HEDLEY_STATIC_CAST(float16_t,    -99.50), HEDLEY_STATIC_CAST(float16_t,    134.00),
        HEDLEY_STATIC_CAST(float16_t,   -781.50), HEDLEY_STATIC_CAST(float16_t,   1188.00), HEDLEY_STATIC_CAST(float16_t,   -106.88), HEDLEY_STATIC_CAST(float16_t,   -497.25) } 
    }
    
    };


int main(){

    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    return 0;
}


void f1(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f32) / sizeof(test_vec_f32[0])) ; i++) {
        float32x2_t a = vld1q_s32(test_vec_f32[i].a);
        float32x2_t rst = vsqrt_f32(a);
        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_f32(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
}

void f2(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f32q) / sizeof(test_vec_f32q[0])) ; i++) {
        float32x4_t a = vld1q_f32(test_vec_f32q[i].a);
        float32x4_t rst = vsqrtq_f32(a);
        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_f32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
}

void f3(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64) / sizeof(test_vec_f64[0])) ; i++) {
        float64x1_t a = vld1_f64(test_vec_f64[i].a);
        float64x1_t rst = vsqrt_f64(a);
        printf("{ ");
        
        test_codegen_f64(rst);
            
        
        printf(" }\n");
    }
}

void f4(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64q) / sizeof(test_vec_f64q[0])) ; i++) {
        float64x2_t a = vld1q_f64(test_vec_f64q[i].a);
        float64x2_t rst = vsqrtq_f64(a);
        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_f64(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
}

void f5(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16h) / sizeof(test_vec_f16h[0])) ; i++) {
        // float16_t a = vld1_f16(test_vec_f32[i].a);
        float16_t rst = vsqrth_f16(test_vec_f32[i].a);
        printf("{ ");

        test_codegen_f16(rst);
        
        printf(" }\n");
    }
}

void f6(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16) / sizeof(test_vec_f16[0])) ; i++) {
        float16x4_t a = vld1_f16(test_vec_f16[i].a);
        float16x4_t rst = vsqrt_f16(a);
        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_f16(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
}

void f7(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16q) / sizeof(test_vec_f16q[0])) ; i++) {
        float16x8_t a = vld1q_f16(test_vec_f16q[i].a);
        float16x8_t rst = vsqrtq_f16(a);
        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_f16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
}