#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int8_t a[16];
    int8_t b[16];
    int16_t r[8];
  } test_vec_s8[] = {
    { {  INT8_C(  56),  INT8_C(  23), -INT8_C(  56), -INT8_C(  88),  INT8_C(  74),  INT8_C(  12), -INT8_C(  61), -INT8_C(   3),
        -INT8_C( 105), -INT8_C(  81),  INT8_C(  34),  INT8_C(  77),  INT8_C(   2),  INT8_C(  78),  INT8_C(  20),  INT8_C(  97) },
      {  INT8_C( 108),  INT8_C(  62),  INT8_C( 122), -INT8_C( 104), -INT8_C(   4), -INT8_C( 113),  INT8_C(  69),  INT8_C(  79),
         INT8_C(  35), -INT8_C(  22), -INT8_C(  92),  INT8_C( 111),  INT8_C(  63),  INT8_C(  97), -INT8_C( 113), -INT8_C( 102) } },
    { {  INT8_C(  28), -INT8_C(  41), -INT8_C( 127),  INT8_C( 108),  INT8_C(  44),  INT8_C(  83),  INT8_C( 111), -INT8_C( 112),
         INT8_C(  30), -INT8_C(  68),  INT8_C(  90), -INT8_C( 122), -INT8_C(  29),  INT8_C(  78), -INT8_C(  53),  INT8_C(  42) },
      {  INT8_C(  81), -INT8_C( 102), -INT8_C(  30),  INT8_C(  47), -INT8_C(  39), -INT8_C(  70),  INT8_C(  20), -INT8_C(  61),
         INT8_C(  68),  INT8_C(  93),  INT8_C(  82), -INT8_C(  16),  INT8_C( 121),  INT8_C(  24),  INT8_C(  60),  INT8_C(  13) } },
    { {  INT8_C(  47), -INT8_C(  30), -INT8_C(  71),  INT8_C(   9),  INT8_C(  95),  INT8_C(  97), -INT8_C(   8), -INT8_C(  18),
         INT8_C(  97), -INT8_C( 100),  INT8_C( 101), -INT8_C(  83), -INT8_C( 112),  INT8_C(  87), -INT8_C(  94),  INT8_C( 119) },
      { -INT8_C(  95), -INT8_C(  34),  INT8_C(  23), -INT8_C(  27), -INT8_C(  72), -INT8_C( 111), -INT8_C(  73),  INT8_C(  21),
        -INT8_C(  30),      INT8_MAX,  INT8_C(  94),  INT8_C(  31),  INT8_C(  75), -INT8_C(   6), -INT8_C(  78), -INT8_C(  54) } },
    { { -INT8_C( 107),  INT8_C(  96),  INT8_C(  64),  INT8_C(  13),  INT8_C(  28),  INT8_C(  10), -INT8_C(  33), -INT8_C(  19),
         INT8_C( 122),  INT8_C(   4),  INT8_C(  27),  INT8_C(  69), -INT8_C(  64), -INT8_C(  28),  INT8_C(  88), -INT8_C(  49) },
      { -INT8_C(  63),  INT8_C(  73),  INT8_C(  94), -INT8_C(  53), -INT8_C(  36),  INT8_C(  49),  INT8_C(  52),  INT8_C(  80),
        -INT8_C(  48), -INT8_C(  12), -INT8_C( 117),  INT8_C( 124),  INT8_C(  31),  INT8_C(  95), -INT8_C(  71),  INT8_C(  35) } },
    { { -INT8_C(   2), -INT8_C( 116), -INT8_C( 104), -INT8_C(   3), -INT8_C( 105), -INT8_C( 112),  INT8_C(  21),  INT8_C( 108),
         INT8_C(  53), -INT8_C(  42), -INT8_C(  91), -INT8_C(  85), -INT8_C(  90),  INT8_C( 113), -INT8_C(  47), -INT8_C(  28) },
      {  INT8_C(  32), -INT8_C(  48), -INT8_C(  98), -INT8_C(  89), -INT8_C(  80), -INT8_C(  70),  INT8_C(  34), -INT8_C(  82),
         INT8_C( 113),  INT8_C(   6),  INT8_C(  65), -INT8_C(   4),  INT8_C(  99),  INT8_C(  12), -INT8_C(  60), -INT8_C( 102) } },
    { {  INT8_C( 102), -INT8_C(  80), -INT8_C( 103), -INT8_C( 122),  INT8_C(  24), -INT8_C( 124), -INT8_C(   8),  INT8_C( 103),
        -INT8_C( 117), -INT8_C(  39), -INT8_C(  27),  INT8_C(   6), -INT8_C(  63),  INT8_C(  22), -INT8_C(  36),  INT8_C(  91) },
      {  INT8_C( 110), -INT8_C( 109), -INT8_C( 118), -INT8_C( 103),  INT8_C(  94), -INT8_C(  93),  INT8_C(  44),  INT8_C(  46),
        -INT8_C(  79), -INT8_C(  23),  INT8_C( 117),  INT8_C( 118), -INT8_C(  31),  INT8_C(  83),  INT8_C(  49),  INT8_C(  44) } },
    { { -INT8_C(  65),  INT8_C(  34),  INT8_C(  23), -INT8_C(  86),  INT8_C(  16), -INT8_C(  97),  INT8_C(  98),  INT8_C(   1),
         INT8_C(  23),  INT8_C( 121), -INT8_C(  37),  INT8_C(  55), -INT8_C(  68),  INT8_C(  37), -INT8_C(   5), -INT8_C(  99) },
      { -INT8_C(  45),  INT8_C(  93), -INT8_C(  61), -INT8_C(  49),  INT8_C(  99),  INT8_C(  34), -INT8_C( 103),  INT8_C(  29),
        -INT8_C(   9), -INT8_C(  14), -INT8_C( 114),  INT8_C(  15),  INT8_C(  22),  INT8_C(  46), -INT8_C( 107), -INT8_C(  94) } },
    { { -INT8_C(  77),  INT8_C(  69), -INT8_C( 115), -INT8_C(  19),  INT8_C(  46), -INT8_C(  90), -INT8_C(  89), -INT8_C( 107),
        -INT8_C( 117), -INT8_C( 124),  INT8_C(  14), -INT8_C(  61),  INT8_C(  58), -INT8_C(  55),  INT8_C(  38), -INT8_C(  89) },
      {  INT8_C(  34),  INT8_C(  40),  INT8_C(   3),  INT8_C(  48),  INT8_C(  39),      INT8_MIN, -INT8_C(  47), -INT8_C(  91),
         INT8_C(  30), -INT8_C(  39),  INT8_C(  74), -INT8_C(  86), -INT8_C( 124),  INT8_C(  96), -INT8_C(   3), -INT8_C(  32) } }
  };

  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec_s16[] = {
    { { -INT16_C( 31408), -INT16_C( 31556),  INT16_C( 17527), -INT16_C( 15966), -INT16_C(  5338), -INT16_C( 14866), -INT16_C( 23628), -INT16_C( 10862) },
      { -INT16_C( 28139),  INT16_C(  2367), -INT16_C( 32111),  INT16_C( 24033), -INT16_C(  2710),  INT16_C( 21412), -INT16_C( 28146),  INT16_C( 11577) } },
    { {  INT16_C( 21956), -INT16_C( 32171), -INT16_C(  5797),  INT16_C( 30391),  INT16_C( 31791), -INT16_C(  9925),  INT16_C( 27209), -INT16_C( 20358) },
      {  INT16_C( 25213), -INT16_C( 16180), -INT16_C( 17248), -INT16_C( 11516),  INT16_C( 31612), -INT16_C( 19780),  INT16_C( 27975), -INT16_C( 30434) } },
    { {  INT16_C( 11539),  INT16_C(  2462), -INT16_C( 22324),  INT16_C(  1497), -INT16_C( 23711),  INT16_C(  3436), -INT16_C( 31079), -INT16_C( 16416) },
      {  INT16_C(   379),  INT16_C( 32139), -INT16_C(  2308),  INT16_C(  7976), -INT16_C( 17076),  INT16_C( 30138), -INT16_C( 15922), -INT16_C(  3122) } },
    { { -INT16_C( 30008),  INT16_C( 29465),  INT16_C(  5712),  INT16_C( 12179),  INT16_C(  9835), -INT16_C( 13545), -INT16_C( 20331),  INT16_C( 20821) },
      { -INT16_C(   332), -INT16_C(  9976), -INT16_C( 30575),  INT16_C( 28277),  INT16_C( 25883), -INT16_C( 15943), -INT16_C( 25951), -INT16_C( 16388) } },
    { { -INT16_C(  6223), -INT16_C( 31448),  INT16_C(  9501),  INT16_C( 12298), -INT16_C(  7071), -INT16_C( 13487), -INT16_C( 28323),  INT16_C( 19907) },
      { -INT16_C( 31606), -INT16_C( 29019), -INT16_C( 17884), -INT16_C( 28720), -INT16_C( 18323), -INT16_C( 25947),  INT16_C( 25202), -INT16_C(  8906) } },
    { { -INT16_C( 15472), -INT16_C( 26443),  INT16_C(  2092), -INT16_C( 12282), -INT16_C( 27856), -INT16_C(   230),  INT16_C( 23822),  INT16_C(   810) },
      { -INT16_C(  8368),  INT16_C(  9149),  INT16_C(  7654), -INT16_C( 31645), -INT16_C( 13063),  INT16_C( 23081), -INT16_C(   256),  INT16_C( 11046) } },
    { { -INT16_C( 26922), -INT16_C( 12841),  INT16_C(  2380),  INT16_C( 28149),  INT16_C( 32540),  INT16_C( 32704),  INT16_C( 29597), -INT16_C(  3215) },
      { -INT16_C(  1921), -INT16_C( 25652), -INT16_C(  4595),  INT16_C(  3622), -INT16_C( 12120),  INT16_C(  6032), -INT16_C(  3476), -INT16_C( 15397) } },
    { { -INT16_C( 10412),  INT16_C( 13944),  INT16_C( 27967),  INT16_C(  3574),  INT16_C( 17708),  INT16_C( 31814), -INT16_C(  1109), -INT16_C( 24029) },
      { -INT16_C( 12049),  INT16_C(  9365),  INT16_C( 29032),  INT16_C( 15453),  INT16_C( 16769),  INT16_C(  5551),  INT16_C( 29070),  INT16_C( 17936) } }
  };

  static const struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[8];
  } test_vec_s32[] = {
    { {  INT32_C(   100398068),  INT32_C(  1826247113),  INT32_C(   717919398),  INT32_C(  1647936604) },
      { -INT32_C(  1052441845), -INT32_C(   148352263),  INT32_C(   902180262),  INT32_C(   762284363) } },
    { { -INT32_C(  1125952914),  INT32_C(    86738123), -INT32_C(  1310004858),  INT32_C(   668966957) },
      { -INT32_C(    40091643), -INT32_C(  1845428604),  INT32_C(  1617654344),  INT32_C(   399981548) } },
    { {  INT32_C(  1500990720),  INT32_C(   657878102),  INT32_C(   355159792),  INT32_C(  1295812041) },
      { -INT32_C(  1793864431),  INT32_C(  1497499436), -INT32_C(   194316388),  INT32_C(   346528371) } },
    { { -INT32_C(  2039860192), -INT32_C(    32710974),  INT32_C(   777853607),  INT32_C(  1815521759) },
      {  INT32_C(   704709272),  INT32_C(   498433798),  INT32_C(   968093395), -INT32_C(   134289677) } },
    { { -INT32_C(   998160586), -INT32_C(  1584857659), -INT32_C(  1979274618),  INT32_C(   624386554) },
      { -INT32_C(   339687571), -INT32_C(  1072737364), -INT32_C(   986115827), -INT32_C(  1610305309) } },
    { { -INT32_C(  1674201521),  INT32_C(   593173639),  INT32_C(  1740776177), -INT32_C(   319455661) },
      {  INT32_C(  1171657221), -INT32_C(   931548966), -INT32_C(   186851502),  INT32_C(  1278145143) } },
    { { -INT32_C(   882860843), -INT32_C(  1593075782), -INT32_C(  1733480879), -INT32_C(   600183380) },
      { -INT32_C(  1877580115), -INT32_C(   350725379),  INT32_C(  1296948359), -INT32_C(   427281934) } },
    { {  INT32_C(  1910309700),  INT32_C(  1274917806),  INT32_C(  1992735109),  INT32_C(  2141344292) },
      { -INT32_C(  1043443522), -INT32_C(  1684860721), -INT32_C(   118108573),  INT32_C(  1341626370) } }
  };

  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec_u8[] = {
    { { UINT8_C(225), UINT8_C(220), UINT8_C( 49), UINT8_C( 63), UINT8_C(104), UINT8_C(126), UINT8_C(122), UINT8_C(121),
        UINT8_C( 89), UINT8_C(177), UINT8_C( 90), UINT8_C(208), UINT8_C(  9), UINT8_C(169), UINT8_C(107), UINT8_C(162) },
      { UINT8_C(213), UINT8_C(230), UINT8_C(228), UINT8_C( 16), UINT8_C(230), UINT8_C(229), UINT8_C(150), UINT8_C(148),
        UINT8_C(102), UINT8_C(249), UINT8_C(217), UINT8_C( 37), UINT8_C( 16), UINT8_C( 27), UINT8_C(129), UINT8_C(176) } },
    { { UINT8_C(110),    UINT8_MAX, UINT8_C( 47), UINT8_C(165), UINT8_C(186), UINT8_C(169), UINT8_C(180), UINT8_C(178),
           UINT8_MAX, UINT8_C(195), UINT8_C( 98), UINT8_C(214), UINT8_C(181), UINT8_C(225), UINT8_C( 55), UINT8_C( 31) },
      { UINT8_C(  8), UINT8_C( 67), UINT8_C(  2), UINT8_C(174), UINT8_C( 82), UINT8_C(160), UINT8_C( 91), UINT8_C(111),
        UINT8_C(207), UINT8_C( 96), UINT8_C(133), UINT8_C(128), UINT8_C(153), UINT8_C(142), UINT8_C(145), UINT8_C(198) } },
    { { UINT8_C(227), UINT8_C( 44), UINT8_C(160), UINT8_C(254), UINT8_C( 85), UINT8_C(105), UINT8_C(205), UINT8_C(192),
        UINT8_C(129), UINT8_C( 23), UINT8_C(242), UINT8_C(  8), UINT8_C( 96), UINT8_C(124), UINT8_C(205), UINT8_C(170) },
      { UINT8_C( 28), UINT8_C(  7), UINT8_C(185), UINT8_C(111), UINT8_C( 46), UINT8_C( 27), UINT8_C( 47), UINT8_C( 43),
        UINT8_C(146), UINT8_C(  3), UINT8_C(236), UINT8_C(154), UINT8_C(132), UINT8_C(200), UINT8_C( 64), UINT8_C( 51) } },
    { { UINT8_C( 34), UINT8_C(  2), UINT8_C(233), UINT8_C(193), UINT8_C(226), UINT8_C( 85), UINT8_C(223), UINT8_C(188),
        UINT8_C( 57), UINT8_C( 18), UINT8_C(153), UINT8_C( 38), UINT8_C(244), UINT8_C( 46), UINT8_C(230), UINT8_C(164) },
      { UINT8_C(189), UINT8_C(213), UINT8_C(170), UINT8_C(120), UINT8_C( 53), UINT8_C(161), UINT8_C(248), UINT8_C(187),
        UINT8_C( 77), UINT8_C( 27), UINT8_C( 81), UINT8_C( 91), UINT8_C(121), UINT8_C(192), UINT8_C(153), UINT8_C(201) } },
    { { UINT8_C(170), UINT8_C(  7), UINT8_C(175), UINT8_C(175), UINT8_C( 22), UINT8_C( 65), UINT8_C(254), UINT8_C( 25),
        UINT8_C( 71), UINT8_C( 17), UINT8_C(200), UINT8_C( 27), UINT8_C(234), UINT8_C(121), UINT8_C(242), UINT8_C(228) },
      { UINT8_C(177), UINT8_C(208), UINT8_C(169), UINT8_C(239), UINT8_C( 92), UINT8_C( 74), UINT8_C(186), UINT8_C(152),
        UINT8_C( 65), UINT8_C( 87), UINT8_C( 46), UINT8_C(109), UINT8_C( 49), UINT8_C(171), UINT8_C(222), UINT8_C(215) } },
    { { UINT8_C( 86), UINT8_C(155), UINT8_C(126), UINT8_C(254), UINT8_C(202), UINT8_C( 33), UINT8_C( 64), UINT8_C(182),
        UINT8_C(  9), UINT8_C( 40), UINT8_C( 56), UINT8_C(235), UINT8_C( 23), UINT8_C( 74), UINT8_C(217), UINT8_C(135) },
      { UINT8_C( 14), UINT8_C( 26), UINT8_C(228), UINT8_C(167), UINT8_C(101), UINT8_C( 88), UINT8_C( 31), UINT8_C( 75),
        UINT8_C( 65), UINT8_C( 31), UINT8_C( 23), UINT8_C(171), UINT8_C(215), UINT8_C( 23), UINT8_C(211), UINT8_C(125) } },
    { { UINT8_C(  8),    UINT8_MAX, UINT8_C(112), UINT8_C(136), UINT8_C( 17), UINT8_C(225), UINT8_C(195), UINT8_C(234),
        UINT8_C(138), UINT8_C(223), UINT8_C( 84), UINT8_C(165), UINT8_C(137), UINT8_C(156), UINT8_C(199), UINT8_C(192) },
      { UINT8_C(116), UINT8_C( 78), UINT8_C( 10), UINT8_C(207), UINT8_C(120), UINT8_C(156), UINT8_C(251), UINT8_C(251),
        UINT8_C(179), UINT8_C(205), UINT8_C(163), UINT8_C(145), UINT8_C( 81), UINT8_C( 15), UINT8_C(252), UINT8_C(242) } },
    { { UINT8_C(103), UINT8_C( 77), UINT8_C(210), UINT8_C(252), UINT8_C( 74), UINT8_C( 72), UINT8_C(179), UINT8_C(147),
        UINT8_C(  2), UINT8_C(241), UINT8_C(152), UINT8_C( 75), UINT8_C( 90), UINT8_C( 14), UINT8_C(239), UINT8_C(161) },
      { UINT8_C( 63), UINT8_C(  7), UINT8_C(111), UINT8_C(158), UINT8_C(181), UINT8_C(203), UINT8_C(212), UINT8_C(  1),
        UINT8_C(123), UINT8_C(237), UINT8_C( 80), UINT8_C(167), UINT8_C(161), UINT8_C( 52), UINT8_C(235), UINT8_C(217) } }
  };

  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[8];
  } test_vec_u16[] = {
    { { UINT16_C(31379), UINT16_C( 2250), UINT16_C(54332), UINT16_C( 9041), UINT16_C( 3394), UINT16_C(51198), UINT16_C(35464), UINT16_C(61264) },
      { UINT16_C(21437), UINT16_C( 1588), UINT16_C(57805), UINT16_C(28006), UINT16_C(31737), UINT16_C(61546), UINT16_C(56118), UINT16_C(35456) } },
    { { UINT16_C(20953), UINT16_C(35581), UINT16_C(38697), UINT16_C(45047), UINT16_C(35635), UINT16_C(53853), UINT16_C(56518), UINT16_C(60030) },
      { UINT16_C(14951), UINT16_C(23661), UINT16_C(32662), UINT16_C(39465), UINT16_C( 8696), UINT16_C(22769), UINT16_C(12608), UINT16_C(25396) } },
    { { UINT16_C(29801), UINT16_C(48181), UINT16_C( 6369), UINT16_C(64542), UINT16_C(13894), UINT16_C(59606), UINT16_C(21338), UINT16_C( 8294) },
      { UINT16_C(14102), UINT16_C( 2628), UINT16_C(18596), UINT16_C(48347), UINT16_C(30380), UINT16_C( 9341), UINT16_C(20491), UINT16_C( 5464) } },
    { { UINT16_C(22544), UINT16_C(25097), UINT16_C(11742), UINT16_C(36454), UINT16_C(65515), UINT16_C(12084), UINT16_C(24810), UINT16_C(14612) },
      { UINT16_C(46901), UINT16_C(15139), UINT16_C(16346), UINT16_C(26881), UINT16_C(14498), UINT16_C(23848), UINT16_C(25682), UINT16_C(62052) } },
    { { UINT16_C(16874), UINT16_C(64382), UINT16_C(56407), UINT16_C(46235), UINT16_C(49928), UINT16_C(28247), UINT16_C(12635), UINT16_C(50297) },
      { UINT16_C(38911), UINT16_C(35799), UINT16_C( 9223), UINT16_C(12141), UINT16_C(36790), UINT16_C(16239), UINT16_C(50838), UINT16_C(14903) } },
    { { UINT16_C(17945), UINT16_C(60083), UINT16_C(14676), UINT16_C(39611), UINT16_C( 1137), UINT16_C(62614), UINT16_C(20895), UINT16_C( 1844) },
      { UINT16_C(42412), UINT16_C(46009), UINT16_C(54644), UINT16_C( 6858), UINT16_C(18702), UINT16_C(42526), UINT16_C( 7025), UINT16_C(27230) } },
    { { UINT16_C(18812), UINT16_C(43138), UINT16_C(17096), UINT16_C(21500), UINT16_C(43609), UINT16_C(34600), UINT16_C(18064), UINT16_C(51793) },
      { UINT16_C( 6318), UINT16_C(14287), UINT16_C(43394), UINT16_C(17947), UINT16_C( 5899), UINT16_C(33328), UINT16_C(29170), UINT16_C(35929) } },
    { { UINT16_C(63331), UINT16_C(61994), UINT16_C(49059), UINT16_C(59344), UINT16_C(49100), UINT16_C(22407), UINT16_C(11973), UINT16_C(10776) },
      { UINT16_C( 5090), UINT16_C( 5624), UINT16_C(53049), UINT16_C(28229), UINT16_C(52033), UINT16_C(15032), UINT16_C(24302), UINT16_C(33253) } }
  };

  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint64_t r[8];
  } test_vec_u32[] = {
    { { UINT32_C(4109551688), UINT32_C(1727012589), UINT32_C(3839438628), UINT32_C(1640783718) },
      { UINT32_C(1947148747), UINT32_C(2022943969), UINT32_C( 617126509), UINT32_C(1379868247) } },
    { { UINT32_C(2027027075), UINT32_C(4032582358), UINT32_C(4065690495), UINT32_C(2574451206) },
      { UINT32_C(1326429635), UINT32_C(  37632411), UINT32_C(4032123754), UINT32_C(2087301267) } },
    { { UINT32_C( 403935999), UINT32_C(3311907537), UINT32_C(1990698035), UINT32_C(3097408373) },
      { UINT32_C( 658350901), UINT32_C(4092683250), UINT32_C( 303932457), UINT32_C(1081275857) } },
    { { UINT32_C(1711167474), UINT32_C(1454888872), UINT32_C(2203619912), UINT32_C( 757866390) },
      { UINT32_C(2890704337), UINT32_C( 106063218), UINT32_C( 915297190), UINT32_C(4038839650) } },
    { { UINT32_C( 461099667), UINT32_C(1313830800), UINT32_C( 943139052), UINT32_C(3205734714) },
      { UINT32_C(1870910144), UINT32_C(1552099649), UINT32_C(2846719708), UINT32_C(1010840842) } },
    { { UINT32_C(1303923406), UINT32_C(2778023749), UINT32_C(2914441445), UINT32_C(1529012976) },
      { UINT32_C(2430804959), UINT32_C( 112043442), UINT32_C(3438860990), UINT32_C(2178443608) } },
    { { UINT32_C(2446509566), UINT32_C(2807420183), UINT32_C(3814353168), UINT32_C(3821892831) },
      { UINT32_C(1766713842), UINT32_C(2474784990), UINT32_C(2085809709), UINT32_C( 427883008) } },
    { { UINT32_C( 830080155), UINT32_C( 231434761), UINT32_C(3005002703), UINT32_C(4192957336) },
      { UINT32_C(1034507225), UINT32_C(2747796276), UINT32_C(2279757546), UINT32_C(2761946154) } }
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

    for (size_t i = 0 ; i < (sizeof(test_vec_s8) / sizeof(test_vec_s8[0])) ; i++) {
        int8x16_t a = vld1q_s8(test_vec_s8[i].a);
        // printf("test:\n");
        // for (int i = 0; i < 8; i++)
        // {
        //     printf("%hd, ", a[i]);
        // }
        // printf("\ntest end\n");
        int8x16_t b = vld1q_s8(test_vec_s8[i].b);
        int16x8_t rst = vabdl_high_s8(a, b);
        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_i16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        int16x8_t b = vld1q_s16(test_vec_s16[i].b);
        int32x4_t rst = vabdl_high_s16(a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_i32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f3(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int32x4_t b = vld1q_s32(test_vec_s32[i].b);
        int64x2_t rst = vabdl_high_s32(a, b);

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_i64(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f4(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u8) / sizeof(test_vec_u8[0])) ; i++) {
        uint8x16_t a = vld1q_u8(test_vec_u8[i].a);
        uint8x16_t b = vld1q_u8(test_vec_u8[i].b);
        uint16x8_t rst = vabdl_high_u8(a, b);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_u16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f5(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint16x8_t b = vld1q_u16(test_vec_u16[i].b);
        uint32x4_t rst = vabdl_high_u16(a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f6(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint32x4_t b = vld1q_u32(test_vec_u32[i].b);
        uint64x2_t rst = vabdl_high_u32(a, b);

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_u64(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}