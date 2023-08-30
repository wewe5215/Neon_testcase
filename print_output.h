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
#include <arm_fp16.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void putchar_uart0( int c );
void print_uart0( const char * s );
void putc_uart0( int c );
void puts_uart0( const char * s );

#ifdef __cplusplus
}
#endif

#define SIMDE_MATH_NAN (__builtin_nan(""))
#define SIMDE_MATH_NANF (__builtin_nanf(""))
static volatile unsigned int * const UART0DR = ( unsigned int * ) ( uintptr_t * ) 0x9000000;

int putchar(int c)
{
    *UART0DR = c; /* Transmit char */
     return c;
}

void putchar_uart0( int c )
{
    *UART0DR = c; /* Transmit char */
}

void putc_uart0( int c )
{
    *UART0DR = c; /* Transmit char */
}

void print_uart0( const char * s )
{
    while( *s != '\0' )                     /* Loop until end of string */
    {
        *UART0DR = ( unsigned int ) ( *s ); /* Transmit char */
        s++;                                /* Next char */
    }
}

void puts_uart0( const char * s )
{
    while( *s != '\0' )                     /* Loop until end of string */
    {
        *UART0DR = ( unsigned int ) ( *s ); /* Transmit char */
        if (*s == '\n') {
           *UART0DR = ( unsigned int ) ( '\r' );
        } 
        s++;                                /* Next char */
    }
}

// angel/semihosting interface
#define SYS_WRITE0                       0x04 
static uint64_t semihosting_call(uint32_t operation, uint64_t parameter)
{
    __asm("HLT #0xF000");
}

// syscall stubs
int _close (int fd)
{
    errno = EBADF;
    return -1;
}

int _isatty (int fd)
{
    return 1;
}

int _fstat (int fd, struct stat * st)
{
    errno = EBADF;
    return -1;
}

off_t _lseek (int fd, off_t ptr, int dir)
{
    errno = EBADF;
    return (off_t) -1;
}

int _read (int fd, void *ptr, size_t len)
{
    errno = EBADF;
    return -1;
}

int _write (int fd, const char *ptr, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        putchar_uart0(ptr[i]);
    }
    return len;
}


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
char buffer[BUFSIZ];

static void
test_codegen_f16(float16_t value) {
  float32_t valuef = HEDLEY_STATIC_CAST(float32_t, value);
  if (isnan(value)) {
    sprintf(buffer, "                   SIMDE_NANF");
    puts_uart0(buffer);
  } else if (isinf(valuef)) {
    sprintf(buffer, "%5cSIMDE_INFINITYHF", valuef < 0 ? '-' : ' ');
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "SIMDE_FLOAT16_VALUE(%9.6f)", HEDLEY_STATIC_CAST(double, valuef));
    puts_uart0(buffer);
  }
}

static void
test_codegen_f32(float32_t value) {
  if (isnan(value)) {
    sprintf(buffer,  "           SIMDE_MATH_NANF");
    puts_uart0(buffer);
  } else if (isinf(value)) {
    sprintf(buffer, "%5cSIMDE_MATH_INFINITYF", value < 0 ? '-' : ' ');
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "SIMDE_FLOAT32_C(%9.6f)", HEDLEY_STATIC_CAST(double, value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_f64(float64_t value) {
  if (isnan(value)) {
    sprintf(buffer, " SIMDE_MATH_NAN");
    puts_uart0(buffer);
  } else if (isinf(value)) {
    sprintf(buffer, "%7cSIMDE_MATH_INFINITY", value < 0 ? '-' : ' ');
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "SIMDE_FLOAT64_C(%9.6f)", HEDLEY_STATIC_CAST(double, value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_i8(int8_t value) {
  if (value == INT8_MIN) {
    sprintf(buffer,  "INT8_MIN");
    puts_uart0(buffer);
  } else if (value == INT8_MAX) {
    sprintf(buffer, "INT8_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "%cINT8_C(%4" PRId8 ")", (value < 0) ? '-' : ' ', (int8_t)((value < 0) ? -value : value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_i16(int16_t value) {
  if (value == INT16_MIN) {
    sprintf(buffer, "%16s", "INT16_MIN");
    puts_uart0(buffer);
  } else if (value == INT16_MAX) {
    sprintf(buffer, "%16s", "INT16_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "%cINT16_C(%6" PRId16 ")", (value < 0) ? '-' : ' ', (int16_t)((value < 0) ? -value : value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_i32(int32_t value) {
  if (value == INT32_MIN) {
    sprintf(buffer, "%22s", "INT32_MIN");
    puts_uart0(buffer);
  } else if (value == INT32_MAX) {
    sprintf(buffer, "%22s", "INT32_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "%cINT32_C(%12" PRId32 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int32_t, (value < 0) ? -value : value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_i64(int64_t value) {
  if (value == INT64_MIN) {
    sprintf(buffer, "%30s", "INT64_MIN");
    puts_uart0(buffer);
  } else if (value == INT64_MAX) {
    sprintf(buffer, "%30s", "INT64_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "%cINT64_C(%20" PRId64 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int64_t, (value < 0) ? -value : value));
    puts_uart0(buffer);
  }
}

static void
test_codegen_u8(uint8_t value) {
  if (value == UINT8_MAX) {
    sprintf(buffer,  "   UINT8_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "UINT8_C(%3" PRIu8 ")", value);
    puts_uart0(buffer);
  }
}

static void
test_codegen_u16(uint16_t value) {
  if (value == UINT16_MAX) {
    sprintf(buffer, "%15s", "UINT16_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "UINT16_C(%5" PRIu16 ")", value);
    puts_uart0(buffer);
  }
}

static void
test_codegen_u32(uint32_t value) {
  if (value == UINT32_MAX) {
    sprintf(buffer, "%20s", "UINT32_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "UINT32_C(%10" PRIu32 ")", value);
    puts_uart0(buffer);
  }
}

static void
test_codegen_u64(uint64_t value) {
  if (value == UINT64_MAX) {
    sprintf(buffer, "%30s", "UINT64_MAX");
    puts_uart0(buffer);
  } else {
    sprintf(buffer, "UINT64_C(%20" PRIu64 ")", value);
    puts_uart0(buffer);
  }
}

void print_float16(float16_t rst){
  // sprintf(buffer, "{ ");
  // puts_uart0(buffer);
  test_codegen_f16(rst);
  sprintf(buffer, "\n");
  puts_uart0(buffer);
}

void print_float16x4(float16x4_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);

  for(int j = 0;j < 4;j ++){
      test_codegen_f16(rst[j]);
      if(j != 3){
        sprintf(buffer, ", ");
        puts_uart0(buffer);
      }
  }

  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_float16x8(float16x8_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
  for(int j = 0;j < 8;j ++){
      test_codegen_f16(rst[j]);
      if(j != 7){
        sprintf(buffer, ", ");
        puts_uart0(buffer);
      }
  }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_float32x2(float32x2_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);

  for(int j = 0;j < 2;j ++){
      test_codegen_f32(rst[j]);
      if(j != 1){
        sprintf(buffer, ", ");
        puts_uart0(buffer);
      }
  }

  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_float32x4(float32x4_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);

  for(int j = 0;j < 4;j ++){
      test_codegen_f32(rst[j]);
      if(j != 3){
          sprintf(buffer, ", ");
          puts_uart0(buffer);
      }
  }

  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_float64x1(float64x1_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
  test_codegen_f64(rst[0]);
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_float64x2(float64x2_t rst){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);

  for(int j = 0;j < 2;j ++){
      test_codegen_f64(rst[j]);
      if(j != 1){
          sprintf(buffer, ", ");
          puts_uart0(buffer);
      }
  }

  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int8x8(int8x8_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 8;j ++){
            test_codegen_i8(r[j]);
            if(j != 7){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int16x4(int16x4_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 4;j ++){
            test_codegen_i16(r[j]);
            if(j != 3){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int32(int32_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
  test_codegen_i32(r);
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int32x2(int32x2_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 2;j ++){
            test_codegen_i32(r[j]);
            if(j != 1){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

// void print_int64x1(int64x1_t r){
//   printf("{ ");
        
//         test_codegen_i64(r[0]);
        
//   printf(" }\n");
// }

void print_int8x16(int8x16_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 16;j ++){
            test_codegen_i8(r[j]);
            if(j != 15){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int16x8(int16x8_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 8;j ++){
            test_codegen_i16(r[j]);
            if(j != 7){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int32x4(int32x4_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 4;j ++){
            test_codegen_i32(r[j]);
            if(j != 3){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_int64x2(int64x2_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 2;j ++){
            test_codegen_i64(r[j]);
            if(j != 1){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint8x8(uint8x8_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 8;j ++){
            test_codegen_u8(r[j]);
            if(j != 7){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint16x4(uint16x4_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 4;j ++){
            test_codegen_u16(r[j]);
            if(j != 3){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint32x2(uint32x2_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 2;j ++){
            test_codegen_u32(r[j]);
            if(j != 1){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

// void print_uint64x1(uint64x1_t r){
//   printf("{ ");
        
//         test_codegen_u64(r[0]);
        
//   printf(" }\n");
// }

void print_uint8x16(uint8x16_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 16;j ++){
            test_codegen_u8(r[j]);
            if(j != 15){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint16x8(uint16x8_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 8;j ++){
            test_codegen_u16(r[j]);
            if(j != 7){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint32x4(uint32x4_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(r[j]);
            if(j != 3){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}

void print_uint64x2(uint64x2_t r){
  sprintf(buffer, "{ ");
  puts_uart0(buffer);
        for(int j = 0;j < 2;j ++){
            test_codegen_u64(r[j]);
            if(j != 1){
              sprintf(buffer, ", ");
              puts_uart0(buffer);
            }
        }
  sprintf(buffer, " }\n");
  puts_uart0(buffer);
}
