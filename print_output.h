#include <stdio.h>
#include <time.h>
#include <arm_neon.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <math.h>

#if defined(HEDLEY_STATIC_CAST)
#  undef HEDLEY_STATIC_CAST
#endif
#if defined(__cplusplus)
#  define HEDLEY_STATIC_CAST(T, expr) (static_cast<T>(expr))
#else
#  define HEDLEY_STATIC_CAST(T, expr) ((T) (expr))
#endif

#  define SIMDE_FLOAT32_C(value) ((float) value)
#  define SIMDE_FLOAT64_C(value) ((double) value)

static void
test_codegen_f16(float16_t value) {
  float32_t valuef = HEDLEY_STATIC_CAST(float32_t, value);
  if (isnan(value)) {
    printf_( "           SIMDE_NANHF");
  } else if (isinf(valuef)) {
    printf_("%5cSIMDE_INFINITYHF", valuef < 0 ? '-' : ' ');
  } else {
    printf_("SIMDE_FLOAT16_VALUE(%9.2f)", HEDLEY_STATIC_CAST(double, valuef));
  }
}

static void
test_codegen_f32(float32_t value) {
  if (isnan(value)) {
    printf_( "           SIMDE_MATH_NANF");
  } else if (isinf(value)) {
    printf_("%5cSIMDE_MATH_INFINITYF", value < 0 ? '-' : ' ');
  } else {
    printf( "SIMDE_FLOAT32_C(%9.2f)", HEDLEY_STATIC_CAST(double, value));
  }
}

static void
test_codegen_f64(float64_t value) {
  if (isnan(value)) {
    printf_("            SIMDE_MATH_NAN");
  } else if (isinf(value)) {
    printf_("%7cSIMDE_MATH_INFINITY", value < 0 ? '-' : ' ');
  } else {
    printf_("SIMDE_FLOAT64_C(%9.2f)", HEDLEY_STATIC_CAST(double, value));
  }
}

static void
test_codegen_i8(int8_t value) {
  if (value == INT8_MIN) {
    printf( "     INT8_MIN");
  } else if (value == INT8_MAX) {
    printf("     INT8_MAX");
  } else {
    printf("%cINT8_C(%4" PRId8 ")", (value < 0) ? '-' : ' ', (int8_t)((value < 0) ? -value : value));
  }
}

static void
test_codegen_i16(int16_t value) {
  if (value == INT16_MIN) {
    printf( "%16s", "INT16_MIN");
  } else if (value == INT16_MAX) {
    printf( "%16s", "INT16_MAX");
  } else {
    printf( "%cINT16_C(%6" PRId16 ")", (value < 0) ? '-' : ' ', (int16_t)((value < 0) ? -value : value));
  }
}

static void
test_codegen_i32(int32_t value) {
  if (value == INT32_MIN) {
    printf( "%22s", "INT32_MIN");
  } else if (value == INT32_MAX) {
    printf( "%22s", "INT32_MAX");
  } else {
    printf( "%cINT32_C(%12" PRId32 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int32_t, (value < 0) ? -value : value));
  }
}

static void
test_codegen_i64(int64_t value) {
  if (value == INT64_MIN) {
    printf( "%30s", "INT64_MIN");
  } else if (value == INT64_MAX) {
    printf( "%30s", "INT64_MAX");
  } else {
    printf( "%cINT64_C(%20" PRId64 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int64_t, (value < 0) ? -value : value));
  }
}

static void
test_codegen_u8(uint8_t value) {
  if (value == UINT8_MAX) {
    printf( "   UINT8_MAX");
  } else {
    printf( "UINT8_C(%3" PRIu8 ")", value);
  }
}

static void
test_codegen_u16(uint16_t value) {
  if (value == UINT16_MAX) {
    printf( "%15s", "UINT16_MAX");
  } else {
    printf( "UINT16_C(%5" PRIu16 ")", value);
  }
}

static void
test_codegen_u32(uint32_t value) {
  if (value == UINT32_MAX) {
    printf( "%20s", "UINT32_MAX");
  } else {
    printf( "UINT32_C(%10" PRIu32 ")", value);
  }
}

static void
test_codegen_u64(uint64_t value) {
  if (value == UINT64_MAX) {
    printf( "%30s", "UINT64_MAX");
  } else {
    printf( "UINT64_C(%20" PRIu64 ")", value);
  }
}
