#include "print_output.h"
void f1();
void f2();
void f3();


static const struct {
    float16_t a;
    float16_t r;
  } test_vec_f16[] = {
    { HEDLEY_STATIC_CAST(float16_t, -774.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, -933.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 510.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, -980.50),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 716.50),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, 875.00),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, -9.65),
    
    },
    { HEDLEY_STATIC_CAST(float16_t, -580.00),
    
    }  
  };

static const struct {
    float a;
    float r;
  } test_vec_f32[] = {
    { SIMDE_FLOAT32_C(     8.79),
    
    },
    { SIMDE_FLOAT32_C(  -399.97),
    
    },
    { SIMDE_FLOAT32_C(   231.75),
    
    },
    { SIMDE_FLOAT32_C(   864.59),
    
    },
    { SIMDE_FLOAT32_C(  -814.20),
    
    },
    { SIMDE_FLOAT32_C(   263.32),
    
    },
    { SIMDE_FLOAT32_C(   321.47),
    
    },
    { SIMDE_FLOAT32_C(   -57.92),
    
    }
  };


  static const struct {
    double a;
    double r;
  } test_vec_f64[] = {
    { SIMDE_FLOAT64_C(  -111.66),
    
    },
    { SIMDE_FLOAT64_C(  -365.17),
    
    },
    { SIMDE_FLOAT64_C(   -45.32),
    
    },
    { SIMDE_FLOAT64_C(  -324.50),
    
    },
    { SIMDE_FLOAT64_C(   611.77),
    
    },
    { SIMDE_FLOAT64_C(   910.11),
    
    },
    { SIMDE_FLOAT64_C(   572.56),
    
    },
    { SIMDE_FLOAT64_C(   265.81),
    
    }
  };
int main(){

    f1();
    f2();
    f3();
    
    return 0;
}

void f1(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f16) / sizeof(test_vec_f16[0])) ; i++) {
        
        float16_t rst = vrecpxs_f16(test_vec_f16[i].a);
        printf("{ ");
        test_codegen_f16(rst);
        
        printf(" }\n");
    }
}

void f2(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f32) / sizeof(test_vec_f32[0])) ; i++) {
        
        float32_t rst = vrecpxs_f32(test_vec_f32[i].a);
        printf("{ ");
        test_codegen_f32(rst);
        
        printf(" }\n");
    }
}

void f3(){
    for (size_t i = 0 ; i < (sizeof(test_vec_f64) / sizeof(test_vec_f64[0])) ; i++) {
        
        float64_t rst = vrecpxs_f64(test_vec_f64[i].a);
        printf("{ ");
        test_codegen_f64(rst);
        
        printf(" }\n");
    }
}