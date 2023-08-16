#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int8_t r[8];
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec_s16[] = {
    { { -INT8_C(  49), -INT8_C(   2), -INT8_C(   4), -INT8_C(  39), -INT8_C(  56),  INT8_C(  92),      INT8_MAX, -INT8_C(  96) },
      {  INT16_C(  2268), -INT16_C( 27896),  INT16_C(  6248), -INT16_C( 20738), -INT16_C( 11421), -INT16_C(  6462),  INT16_C(  9141), -INT16_C(  8633) } },
    { { -INT8_C(  56), -INT8_C(   5), -INT8_C(  49),  INT8_C(   8),  INT8_C(  95), -INT8_C(  17), -INT8_C(  89),  INT8_C(  32) },
      { -INT16_C(  5037),  INT16_C( 24701),  INT16_C( 27716), -INT16_C(  8586),  INT16_C(  2478), -INT16_C( 12465),  INT16_C( 21913), -INT16_C( 15953) } },
    { {  INT8_C(  93),  INT8_C(  77),  INT8_C( 115), -INT8_C(  87),  INT8_C(  20),  INT8_C(  67), -INT8_C(  86),  INT8_C( 103) },
      {  INT16_C( 30051), -INT16_C( 12977), -INT16_C( 28735),  INT16_C( 13221), -INT16_C( 23479), -INT16_C( 11971), -INT16_C( 19198),  INT16_C( 12154) } },
    { {  INT8_C(  63),  INT8_C(  12),  INT8_C(  41),  INT8_C(  27), -INT8_C(  27), -INT8_C(  61), -INT8_C(  79), -INT8_C(  98) },
      {  INT16_C(  1034),  INT16_C( 29868), -INT16_C(  1069), -INT16_C( 16178), -INT16_C( 21507),  INT16_C( 25561), -INT16_C( 13503), -INT16_C(  5754) } },
    { {  INT8_C(  36), -INT8_C(  17), -INT8_C(  50),  INT8_C(  87), -INT8_C(  27), -INT8_C(  80),  INT8_C(  52), -INT8_C(  40) },
      { -INT16_C( 25492),  INT16_C( 31682), -INT16_C( 23652),  INT16_C(  1226), -INT16_C( 13978), -INT16_C( 18138),  INT16_C( 14071),  INT16_C( 18194) } },
    { { -INT8_C(  15), -INT8_C(  47),  INT8_C(  21),  INT8_C(  57),  INT8_C(  49),  INT8_C( 114), -INT8_C(  26),  INT8_C(  26) },
      { -INT16_C( 24850),  INT16_C( 27921),  INT16_C( 10225),  INT16_C( 18898), -INT16_C(   823),  INT16_C( 32750),  INT16_C( 12322), -INT16_C( 11973) } },
    { {  INT8_C( 116),  INT8_C(  69),  INT8_C(  80), -INT8_C(  97), -INT8_C(  62), -INT8_C(  18), -INT8_C(  17),  INT8_C(  91) },
      { -INT16_C( 32478), -INT16_C( 29161), -INT16_C(  5513),  INT16_C( 30671), -INT16_C(  6427),  INT16_C( 26818),  INT16_C( 29508), -INT16_C( 29198) } },
    { { -INT8_C(   8),  INT8_C(  69),  INT8_C( 118), -INT8_C( 118), -INT8_C(  84), -INT8_C(  99),  INT8_C(  96),  INT8_C(  52) },
      { -INT16_C( 11442),  INT16_C(  3919), -INT16_C(  5076),  INT16_C( 20319),  INT16_C( 23238),  INT16_C( 16682), -INT16_C( 20027),  INT16_C( 13791) } }
  };

static const struct {
    int16_t r[4];
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec_s32[] = {
     { { -INT16_C( 15606),  INT16_C(  2806), -INT16_C( 16885), -INT16_C( 17788) },
      {  INT32_C(   676693500), -INT32_C(   698478348), -INT32_C(  1056217790),  INT32_C(  1447200852) } },
    { { -INT16_C( 24763), -INT16_C( 25714), -INT16_C( 10296), -INT16_C( 16279) },
      {  INT32_C(   128340667),  INT32_C(  1538538614),  INT32_C(  1409538197),  INT32_C(   214213867) } },
    { {  INT16_C( 23525),  INT16_C( 20018),  INT16_C( 25083),  INT16_C( 28872) },
      {  INT32_C(   541446154),  INT32_C(  1637908582), -INT32_C(  1657458872), -INT32_C(   490050893) } },
    { { -INT16_C( 29295), -INT16_C( 12866),  INT16_C( 25974),  INT16_C(  1586) },
      {  INT32_C(   993813800),  INT32_C(  1540302069),  INT32_C(  1557614428), -INT32_C(   155492115) } },
    { { -INT16_C( 10359),  INT16_C(  7413),  INT16_C( 20190),  INT16_C(  4887) },
      {  INT32_C(  1640513316), -INT32_C(   167882979),  INT32_C(   108356208),  INT32_C(  2119253925) } },
    { { -INT16_C(  1742), -INT16_C( 20715),  INT16_C( 14928), -INT16_C( 26854) },
      {  INT32_C(  1957363829),  INT32_C(  1960227834),  INT32_C(   934671676),  INT32_C(  1188842440) } },
    { {  INT16_C( 15017),  INT16_C( 14078), -INT16_C( 21905), -INT16_C( 10043) },
      {  INT32_C(   568641287),  INT32_C(  1232100693), -INT32_C(   937886794), -INT32_C(  1173067031) } },
    { {  INT16_C( 16602),  INT16_C( 10154),  INT16_C( 11373), -INT16_C( 15738) },
      {  INT32_C(  1792720480), -INT32_C(   242705108),  INT32_C(   704538807), -INT32_C(  1427955500) } }
  };

  static const struct {
    int32_t r[2];
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec_s64[] = {
    { { -INT32_C(   192998592),  INT32_C(   949453918) },
      { -INT64_C( 4081754609680885914), -INT64_C( 4521805721478854440) } },
    { {  INT32_C(  2109597005), -INT32_C(  1590269980) },
      {  INT64_C( 5386466598467462888),  INT64_C( 8145179019610110471) } },
    { {  INT32_C(   386126876), -INT32_C(  1522221300) },
      {  INT64_C(  860214024042461662), -INT64_C( 4001762143620183561) } },
    { {  INT32_C(  1169213686), -INT32_C(   935846670) },
      {  INT64_C( 5405265556903191834),  INT64_C( 7385517121024881245) } },
    { {  INT32_C(    11215301),  INT32_C(  1862844520) },
      { -INT64_C( 1285501140964284715), -INT64_C( 7248023532021392201) } },
    { {  INT32_C(   499175539), -INT32_C(  2057540137) },
      {  INT64_C( 5987167434647258186),  INT64_C( 5717435040498619655) } },
    { {  INT32_C(  1051532261), -INT32_C(  1371415297) },
      {  INT64_C( 4123730226933162322),  INT64_C( 5365391041494472374) } },
    { {  INT32_C(  1301092100), -INT32_C(   835546280) },
      { -INT64_C( 5285879355950227528),  INT64_C(   82068787711680140) } }
  };

  static const struct {
    uint8_t r[8];
    uint16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec_u16[] = {
    { { UINT8_C(  7), UINT8_C(168), UINT8_C( 40), UINT8_C(124), UINT8_C( 55), UINT8_C(116), UINT8_C( 23), UINT8_C( 92) },
      { UINT16_C( 1711), UINT16_C(18715), UINT16_C(34381), UINT16_C(62124), UINT16_C(58238), UINT16_C(46064), UINT16_C(28988), UINT16_C(59989) } },
    { { UINT8_C(236), UINT8_C(140), UINT8_C(116), UINT8_C( 66), UINT8_C(241), UINT8_C( 63), UINT8_C(161), UINT8_C(183) },
      { UINT16_C( 5026), UINT16_C(37586), UINT16_C(40937), UINT16_C(12524), UINT16_C(31150), UINT16_C(41367), UINT16_C(10720), UINT16_C( 5614) } },
    { { UINT8_C(213), UINT8_C(185), UINT8_C( 58), UINT8_C(202), UINT8_C(179), UINT8_C(222), UINT8_C( 46), UINT8_C(124) },
      { UINT16_C(55880), UINT16_C(50293), UINT16_C(56343), UINT16_C(16869), UINT16_C(56033), UINT16_C(43638), UINT16_C( 2736), UINT16_C(31184) } },
    { { UINT8_C(189), UINT8_C( 28), UINT8_C(173), UINT8_C(226), UINT8_C(174), UINT8_C( 60), UINT8_C(251), UINT8_C(146) },
      { UINT16_C(43710), UINT16_C(27581), UINT16_C( 2288), UINT16_C(32643), UINT16_C(31576), UINT16_C(57299), UINT16_C(17500), UINT16_C(14828) } },
    { { UINT8_C(178), UINT8_C(134), UINT8_C(109), UINT8_C( 64), UINT8_C(230), UINT8_C(253), UINT8_C(107), UINT8_C(104) },
      { UINT16_C(20998), UINT16_C(20827), UINT16_C(22655), UINT16_C(61779), UINT16_C(22198), UINT16_C( 5744), UINT16_C(38614), UINT16_C(55946) } },
    { { UINT8_C(141), UINT8_C( 72), UINT8_C( 60), UINT8_C(194), UINT8_C(181), UINT8_C( 74), UINT8_C(164), UINT8_C(164) },
      { UINT16_C(17193), UINT16_C( 7372), UINT16_C(28502), UINT16_C( 5143), UINT16_C(21112), UINT16_C(14131), UINT16_C(59392), UINT16_C( 6557) } },
    { { UINT8_C(204), UINT8_C(205), UINT8_C(104), UINT8_C(253), UINT8_C(211), UINT8_C(156), UINT8_C(189), UINT8_C( 50) },
      { UINT16_C(40167), UINT16_C(59066), UINT16_C(13686), UINT16_C(38166), UINT16_C(16146), UINT16_C(57068), UINT16_C(16941), UINT16_C(61130) } },
    { { UINT8_C( 24), UINT8_C( 67), UINT8_C(166), UINT8_C( 50), UINT8_C(122), UINT8_C( 46), UINT8_C( 74), UINT8_C(122) },
      { UINT16_C(29875), UINT16_C( 4321), UINT16_C(22610), UINT16_C(56646), UINT16_C(62410), UINT16_C(56950), UINT16_C(16008), UINT16_C(58757) } }
  };


  static const struct {
    uint16_t r[4];
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec_u32[] = {
    { { UINT16_C( 2704), UINT16_C(35053), UINT16_C(33011), UINT16_C(11258) },
      { UINT32_C(2135317855), UINT32_C(1061043333), UINT32_C( 155442656), UINT32_C(3428840503) } },
    { { UINT16_C(35286), UINT16_C( 9851), UINT16_C( 4255), UINT16_C(55965) },
      { UINT32_C( 306180267), UINT32_C( 847289988), UINT32_C(1242367368), UINT32_C(2020733374) } },
    { { UINT16_C(42645), UINT16_C(33064), UINT16_C(15952), UINT16_C(31164) },
      { UINT32_C(4001756089), UINT32_C(3666887026), UINT32_C(4146551531), UINT32_C( 243447295) } },
    { { UINT16_C(60652), UINT16_C(65189), UINT16_C(65152), UINT16_C(18844) },
      { UINT32_C(4133640451), UINT32_C(3639503053), UINT32_C(3988636682), UINT32_C( 356702445) } },
    { { UINT16_C(11753), UINT16_C(48453), UINT16_C(49858), UINT16_C(55385) },
      { UINT32_C(2410359635), UINT32_C( 450419865), UINT32_C(3724495701), UINT32_C(1137626037) } },
    { { UINT16_C( 9755), UINT16_C(11141), UINT16_C(49771), UINT16_C(13934) },
      { UINT32_C(2350522860), UINT32_C( 611640412), UINT32_C(3421922895), UINT32_C(3309948926) } },
    { { UINT16_C(30415), UINT16_C(45651), UINT16_C(40031), UINT16_C(26844) },
      { UINT32_C(3443358672), UINT32_C( 264919016), UINT32_C(3045993336), UINT32_C(1967168391) } },
    { { UINT16_C(58255), UINT16_C(42720), UINT16_C(57474), UINT16_C(49089) },
      { UINT32_C(4294793694), UINT32_C( 933999333), UINT32_C(3926456185), UINT32_C(1210963005) } }
  };


  static const struct {
    uint32_t r[2];
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec_u64[] = {
    { { UINT32_C(1114951145), UINT32_C(2769158938) },
      { UINT64_C( 5650012626760478259), UINT64_C(14934852916637915184) } },
    { { UINT32_C(1402029215), UINT32_C( 196729935) },
      { UINT64_C( 6267062357568356613), UINT64_C(12637209202647282729) } },
    { { UINT32_C(3931706827), UINT32_C(1888195967) },
      { UINT64_C(13258019279381731814), UINT64_C( 6902859578328813207) } },
    { { UINT32_C( 822861947), UINT32_C(1248836607) },
      { UINT64_C( 7326185336737781025), UINT64_C( 9879767103301738455) } },
    { { UINT32_C(1007151614), UINT32_C( 971233198) },
      { UINT64_C(16041821339270201002), UINT64_C(17470801195624355623) } },
    { { UINT32_C(1856588222), UINT32_C(1274133064) },
      { UINT64_C( 8151218842687542731), UINT64_C(12531828023036219907) } },
    { { UINT32_C(3404838509), UINT32_C(1170565492) },
      { UINT64_C(  304925232105649789), UINT64_C( 1205004352784170321) } },
    { { UINT32_C(1472658418), UINT32_C(2916633085) },
      { UINT64_C( 7058253452444419888), UINT64_C(11870841006473416036) } }
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
    printf("qrshrn_high_s16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        int8x8_t  r = vld1_s8(test_vec_s16[i].r);
        print_int8x16(vqrshrn_high_s16(r, a, 1));
        print_int8x16(vqrshrn_high_s16(r, a, 3));
        print_int8x16(vqrshrn_high_s16(r, a, 5));
        print_int8x16(vqrshrn_high_s16(r, a, 6));
        print_int8x16(vqrshrn_high_s16(r, a, 8));
    }
    
}

void f2(){
    printf("qrshrn_high_s32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int16x4_t r = vld1_s16(test_vec_s32[i].r);
        print_int16x8(vqrshrn_high_s32(r, a, 3));
        print_int16x8(vqrshrn_high_s32(r, a, 6));
        print_int16x8(vqrshrn_high_s32(r, a, 10));
        print_int16x8(vqrshrn_high_s32(r, a, 13));
        print_int16x8(vqrshrn_high_s32(r, a, 16));

        
    }
    
}

void f3(){
    printf("qrshrn_high_s64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        int32x2_t  r = vld1_s32(test_vec_s64[i].r);
        print_int32x4(vqrshrn_high_s64(r, a, 6));
        print_int32x4(vqrshrn_high_s64(r, a, 13));
        print_int32x4(vqrshrn_high_s64(r, a, 19));
        print_int32x4(vqrshrn_high_s64(r, a, 26));
        print_int32x4(vqrshrn_high_s64(r, a, 32));
    }
    
}

void f4(){
    printf("qrshrn_high_u16:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint8x8_t  r = vld1_u8(test_vec_u16[i].r);

        print_uint8x16(vqrshrn_high_u16(r, a, 1));
        print_uint8x16(vqrshrn_high_u16(r, a, 3));
        print_uint8x16(vqrshrn_high_u16(r, a, 5));
        print_uint8x16(vqrshrn_high_u16(r, a, 6));
        print_uint8x16(vqrshrn_high_u16(r, a, 8));
    }
    
}

void f5(){
    printf("qrshrn_high_u32:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint16x4_t  r = vld1_u16(test_vec_u32[i].r);
        print_uint16x8(vqrshrn_high_u32(r, a, 3));
        print_uint16x8(vqrshrn_high_u32(r, a, 6));
        print_uint16x8(vqrshrn_high_u32(r, a, 10));
        print_uint16x8(vqrshrn_high_u32(r, a, 13));
        print_uint16x8(vqrshrn_high_u32(r, a, 16));
    }
    
}

void f6(){
    printf("qrshrn_high_u64:\n");
    for (size_t i = 0 ; i < (sizeof(test_vec_u64) / sizeof(test_vec_u64[0])) ; i++) {
        uint64x2_t a = vld1q_u64(test_vec_u64[i].a);
        uint32x2_t  r = vld1_u32(test_vec_u64[i].r);
        print_uint32x4(vqrshrn_high_u64(r, a, 6));
        print_uint32x4(vqrshrn_high_u64(r, a, 13));
        print_uint32x4(vqrshrn_high_u64(r, a, 19));
        print_uint32x4(vqrshrn_high_u64(r, a, 26));
        print_uint32x4(vqrshrn_high_u64(r, a, 32));
    }
    
}