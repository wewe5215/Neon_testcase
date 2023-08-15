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
    { SIMDE_FLOAT16_VALUE(   279.00),
    
    },
    { SIMDE_FLOAT16_VALUE(   505.00),
    
    },
    { SIMDE_FLOAT16_VALUE(    91.44),
    
    },
    { SIMDE_FLOAT16_VALUE(   217.50),
    
    },
    { SIMDE_FLOAT16_VALUE(   903.00),
    
    },
    { SIMDE_FLOAT16_VALUE(  -717.50),
    
    },
    { SIMDE_FLOAT16_VALUE(    45.19),
    
    },
    { SIMDE_FLOAT16_VALUE(   148.88),
    
    }  
  };


  static const struct {
      float16_t a[4];
      float16_t r[4];
    } test_vec_f16[] = {
      { { SIMDE_FLOAT16_VALUE(  -228.12), SIMDE_FLOAT16_VALUE(   -98.75), SIMDE_FLOAT16_VALUE(   350.00), SIMDE_FLOAT16_VALUE(  -598.00) }
      
      },
    { { SIMDE_FLOAT16_VALUE(  -136.50), SIMDE_FLOAT16_VALUE(  -721.00), SIMDE_FLOAT16_VALUE(  -692.00), SIMDE_FLOAT16_VALUE(  -858.00) } 
    
    },
    { { SIMDE_FLOAT16_VALUE(  -990.00), SIMDE_FLOAT16_VALUE(   258.50), SIMDE_FLOAT16_VALUE(   727.00), SIMDE_FLOAT16_VALUE(   -48.00) } 
    
    },
    { { SIMDE_FLOAT16_VALUE(   617.00), SIMDE_FLOAT16_VALUE(  -746.00), SIMDE_FLOAT16_VALUE(   -75.25), SIMDE_FLOAT16_VALUE(   -41.00) } 
    
    },
    { { SIMDE_FLOAT16_VALUE(  -718.00), SIMDE_FLOAT16_VALUE(  -271.25), SIMDE_FLOAT16_VALUE(  -665.00), SIMDE_FLOAT16_VALUE(   877.50) } 
    
    },
    { { SIMDE_FLOAT16_VALUE(  -662.00), SIMDE_FLOAT16_VALUE(  -253.50), SIMDE_FLOAT16_VALUE(   223.25), SIMDE_FLOAT16_VALUE( -1405.00) } 
    
    },
    { { SIMDE_FLOAT16_VALUE( -1530.00), SIMDE_FLOAT16_VALUE(  -257.50), SIMDE_FLOAT16_VALUE(  -206.00), SIMDE_FLOAT16_VALUE(   801.50) } 
    
    },
    { { SIMDE_FLOAT16_VALUE(  -594.00), SIMDE_FLOAT16_VALUE( -1314.00), SIMDE_FLOAT16_VALUE(  -596.50), SIMDE_FLOAT16_VALUE(  1568.00) } 
    
    }
    
    };

static const struct {
      float16_t a[8];
      float16_t r[8];
    } test_vec_f16q[] = {
      { { SIMDE_FLOAT16_VALUE(  1125.00), SIMDE_FLOAT16_VALUE(  1424.00), SIMDE_FLOAT16_VALUE(   113.38), SIMDE_FLOAT16_VALUE(   109.50),
        SIMDE_FLOAT16_VALUE(   -27.50), SIMDE_FLOAT16_VALUE(   142.50), SIMDE_FLOAT16_VALUE(  -435.75), SIMDE_FLOAT16_VALUE(   388.00) } 
      },
    { { SIMDE_FLOAT16_VALUE(  -854.50), SIMDE_FLOAT16_VALUE(   844.50), SIMDE_FLOAT16_VALUE( -1528.00), SIMDE_FLOAT16_VALUE(   542.00),
        SIMDE_FLOAT16_VALUE(   631.00), SIMDE_FLOAT16_VALUE(  -426.00), SIMDE_FLOAT16_VALUE(  1139.00), SIMDE_FLOAT16_VALUE(   359.00) } 
    },
    { { SIMDE_FLOAT16_VALUE(   918.50), SIMDE_FLOAT16_VALUE(   -50.50), SIMDE_FLOAT16_VALUE(   -25.00), SIMDE_FLOAT16_VALUE(   892.00),
        SIMDE_FLOAT16_VALUE(    91.88), SIMDE_FLOAT16_VALUE(  -461.00), SIMDE_FLOAT16_VALUE(  -720.00), SIMDE_FLOAT16_VALUE( -1230.00) } 
    },
    { { SIMDE_FLOAT16_VALUE(   195.50), SIMDE_FLOAT16_VALUE(   146.50), SIMDE_FLOAT16_VALUE(  1512.00), SIMDE_FLOAT16_VALUE(   826.00),
        SIMDE_FLOAT16_VALUE(  -279.00), SIMDE_FLOAT16_VALUE(   652.00), SIMDE_FLOAT16_VALUE(  -814.50), SIMDE_FLOAT16_VALUE(  -217.88) } 
    },
    { { SIMDE_FLOAT16_VALUE(   833.00), SIMDE_FLOAT16_VALUE(  1572.00), SIMDE_FLOAT16_VALUE(    87.00), SIMDE_FLOAT16_VALUE( -1076.00),
        SIMDE_FLOAT16_VALUE(  -889.50), SIMDE_FLOAT16_VALUE(  1367.00), SIMDE_FLOAT16_VALUE(  -306.00), SIMDE_FLOAT16_VALUE(  -758.00) } 
    },
    { { SIMDE_FLOAT16_VALUE(  -216.25), SIMDE_FLOAT16_VALUE( -1884.00), SIMDE_FLOAT16_VALUE(   317.00), SIMDE_FLOAT16_VALUE(  -495.25),
        SIMDE_FLOAT16_VALUE(   767.50), SIMDE_FLOAT16_VALUE(  1502.00), SIMDE_FLOAT16_VALUE(  -713.00), SIMDE_FLOAT16_VALUE(  -240.75) } 
    },
    { { SIMDE_FLOAT16_VALUE(   659.50), SIMDE_FLOAT16_VALUE(  -156.50), SIMDE_FLOAT16_VALUE( -1025.00), SIMDE_FLOAT16_VALUE(  -229.50),
        SIMDE_FLOAT16_VALUE(  1210.00), SIMDE_FLOAT16_VALUE(   669.00), SIMDE_FLOAT16_VALUE(  -988.00), SIMDE_FLOAT16_VALUE(  -984.00) } 
    },
    { { SIMDE_FLOAT16_VALUE(  -634.00), SIMDE_FLOAT16_VALUE(  -283.75), SIMDE_FLOAT16_VALUE(   -99.50), SIMDE_FLOAT16_VALUE(   134.00),
        SIMDE_FLOAT16_VALUE(  -781.50), SIMDE_FLOAT16_VALUE(  1188.00), SIMDE_FLOAT16_VALUE(  -106.88), SIMDE_FLOAT16_VALUE(  -497.25) } 
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
        
        float32x2_t rst = vsqrt_f32(test_vec_f32[i].a);
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
        
        float32x4_t rst = vsqrtq_f32(test_vec_f32q[i].a);
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
        
        float64x1_t rst = vsqrt_f64(test_vec_f64[i].a);
        printf("{ ");
        
        test_codegen_f64(rst);
            
        
        printf(" }\n");
    }
}

void f4(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64q) / sizeof(test_vec_f64q[0])) ; i++) {
        
        float64x2_t rst = vsqrtq_f64(test_vec_f64q[i].a);
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
        
        float16_t rst = vsqrth_f16(test_vec_f32[i].a);
        printf("{ ");

        test_codegen_f16(rst);
        
        printf(" }\n");
    }
}

void f6(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16) / sizeof(test_vec_f16[0])) ; i++) {
        
        float16x4_t rst = vsqrt_f16(test_vec_f16[i].a);
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
        
        float16x8_t rst = vsqrtq_f16(test_vec_f16q[i].a);
        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_f16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
}