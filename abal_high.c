#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int16_t a[8];
    int8_t b[16];
    int8_t c[16];
  } test_vec_s8[] = {
    { {  INT16_C( 31527), -INT16_C( 23861), -INT16_C( 22499), -INT16_C( 25397), -INT16_C( 26363), -INT16_C( 29324),  INT16_C(  9147),  INT16_C( 11985) },
      {      INT8_MAX, -INT8_C(  84), -INT8_C(  51),  INT8_C(  45), -INT8_C(  53),  INT8_C(  58),  INT8_C(  35), -INT8_C( 121),
        -INT8_C(  80),  INT8_C(  30),  INT8_C(  90),  INT8_C( 116), -INT8_C(  16),  INT8_C(  77),  INT8_C(  17),  INT8_C(   7) },
      {  INT8_C(  13),  INT8_C(  99), -INT8_C(  85),  INT8_C(  50), -INT8_C(  79),  INT8_C(  58),  INT8_C(  97), -INT8_C(  55),
        -INT8_C(  33), -INT8_C( 118),  INT8_C(  40), -INT8_C(  12), -INT8_C(  37),  INT8_C(   2),  INT8_C(  54),  INT8_C( 106) } },
    { {  INT16_C( 29146), -INT16_C( 13851), -INT16_C( 22392),  INT16_C( 17765),  INT16_C( 30813),  INT16_C( 13385),  INT16_C( 28257), -INT16_C( 20241) },
      { -INT8_C(  47),  INT8_C(  36),  INT8_C(  20),  INT8_C(  52),  INT8_C(  54),  INT8_C(  94),  INT8_C(  10), -INT8_C(  99),
         INT8_C(  52),  INT8_C(  16),  INT8_C(  25),  INT8_C(  23),  INT8_C(  21), -INT8_C(  73), -INT8_C(  22), -INT8_C(  90) },
      { -INT8_C(  77),  INT8_C(  23), -INT8_C(  82), -INT8_C(  97),  INT8_C( 118), -INT8_C(  80),  INT8_C(  50),  INT8_C( 104),
        -INT8_C(  12), -INT8_C( 107), -INT8_C(  84), -INT8_C( 102),  INT8_C(  18), -INT8_C(  81), -INT8_C(  65), -INT8_C(  64) } },
    { {  INT16_C( 13675), -INT16_C(  5244), -INT16_C(  7011),  INT16_C( 13381), -INT16_C( 26410), -INT16_C( 14398), -INT16_C(  7581), -INT16_C( 20529) },
      { -INT8_C(  61), -INT8_C(  32), -INT8_C(   4),      INT8_MAX,  INT8_C( 123), -INT8_C(  91),  INT8_C(  57),  INT8_C(  91),
        -INT8_C(  69), -INT8_C(  42),  INT8_C(   8),  INT8_C(  48),  INT8_C(  29),  INT8_C(  34),  INT8_C(  39),  INT8_C(  50) },
      {  INT8_C( 111),  INT8_C(  71),  INT8_C(   7),  INT8_C(  46),  INT8_C(  84),  INT8_C(  89),  INT8_C(  12), -INT8_C( 100),
         INT8_C(   8), -INT8_C(  60), -INT8_C( 122), -INT8_C(   8),  INT8_C(   0),  INT8_C( 113),  INT8_C(  87),  INT8_C(  54) } },
    { { -INT16_C(  6026),  INT16_C(  8917),  INT16_C( 26873), -INT16_C( 30786), -INT16_C( 13477),  INT16_C( 25684),  INT16_C( 23999),  INT16_C( 19792) },
      { -INT8_C(  11),  INT8_C(  67),  INT8_C(  69), -INT8_C(  41), -INT8_C(   2),  INT8_C( 110), -INT8_C(  58), -INT8_C(  82),
         INT8_C(  30),  INT8_C(  40), -INT8_C( 126), -INT8_C(   4), -INT8_C(  26), -INT8_C(  56),  INT8_C(  51),  INT8_C(  96) },
      {  INT8_C(  67), -INT8_C(  84),  INT8_C(   8),  INT8_C(  32),  INT8_C(   9),  INT8_C(  83),  INT8_C(   7), -INT8_C(  87),
        -INT8_C(   9),      INT8_MAX,  INT8_C(  68),  INT8_C(  56),  INT8_C(  82),  INT8_C(  25),  INT8_C(  31), -INT8_C(  67) } },
    { {  INT16_C( 22382),  INT16_C( 15506),  INT16_C( 23098), -INT16_C(  7625),  INT16_C(  5140), -INT16_C( 19113), -INT16_C(  7601),  INT16_C( 25602) },
      {  INT8_C(  16), -INT8_C( 118), -INT8_C(  78), -INT8_C(  20), -INT8_C(  70),  INT8_C(  22), -INT8_C(  51),  INT8_C(  45),
         INT8_C(  80), -INT8_C(  72), -INT8_C( 100), -INT8_C(   6),  INT8_C(  77), -INT8_C(  32),  INT8_C(  91), -INT8_C(  89) },
      { -INT8_C( 119), -INT8_C(   9), -INT8_C(   7), -INT8_C(  91),  INT8_C(  88),  INT8_C(  71),  INT8_C( 103),  INT8_C(  42),
         INT8_C(  54),  INT8_C(  89), -INT8_C(   5), -INT8_C(  54),  INT8_C(  50),  INT8_C( 124),  INT8_C(   0),  INT8_C(  25) } },
    { {  INT16_C( 19851), -INT16_C( 15664), -INT16_C( 22194),  INT16_C( 32168),  INT16_C( 17889), -INT16_C(   904), -INT16_C( 21691), -INT16_C( 16673) },
      {  INT8_C(  12), -INT8_C(  25),  INT8_C(  78), -INT8_C(  61),  INT8_C(  28), -INT8_C(  81), -INT8_C( 105), -INT8_C(  62),
        -INT8_C(  75),  INT8_C(  18), -INT8_C( 121), -INT8_C(  29), -INT8_C(  65),  INT8_C(  59), -INT8_C(  77), -INT8_C( 109) },
      { -INT8_C( 117), -INT8_C(  78), -INT8_C(  52), -INT8_C(  94),  INT8_C( 123),  INT8_C(  39),  INT8_C( 123),  INT8_C(  93),
        -INT8_C(   6),  INT8_C(  59), -INT8_C(  97),  INT8_C(  70), -INT8_C(  25), -INT8_C( 111), -INT8_C(  59),  INT8_C(  90) } },
    { {  INT16_C( 15542),  INT16_C(  9269), -INT16_C( 13702),  INT16_C(  2348),  INT16_C( 25417), -INT16_C(  9725), -INT16_C( 12834), -INT16_C( 18794) },
      {  INT8_C( 109), -INT8_C(  20),  INT8_C(  13),  INT8_C(  70), -INT8_C(  90), -INT8_C(  70), -INT8_C(  25),  INT8_C(  61),
        -INT8_C(  30),  INT8_C(  67), -INT8_C(  50),  INT8_C(  82), -INT8_C(   9),  INT8_C( 100), -INT8_C( 105), -INT8_C( 112) },
      {  INT8_C(  27),  INT8_C( 104),  INT8_C(  58), -INT8_C(  87),  INT8_C(  88), -INT8_C(  18), -INT8_C( 100),  INT8_C(  87),
        -INT8_C(  47),  INT8_C(  72),  INT8_C(  53), -INT8_C(  14), -INT8_C(  80),  INT8_C(  21), -INT8_C(  51), -INT8_C(  54) } },
    { {  INT16_C( 10866),  INT16_C(  5507), -INT16_C( 32480), -INT16_C( 27979), -INT16_C(  9226), -INT16_C( 18169),  INT16_C( 23885),  INT16_C( 17021) },
      {      INT8_MIN,  INT8_C(  58), -INT8_C(  43), -INT8_C(   3),  INT8_C(  69), -INT8_C(   6),  INT8_C(  94), -INT8_C(  47),
        -INT8_C(  21),  INT8_C(  84),  INT8_C( 110),  INT8_C(  13),  INT8_C(   7),  INT8_C(  74), -INT8_C(  51),  INT8_C(  22) },
      {  INT8_C(  29),  INT8_C(  30),  INT8_C(  53),  INT8_C(  28),  INT8_C( 104),  INT8_C( 116),  INT8_C(  69),  INT8_C(  41),
        -INT8_C(  64), -INT8_C( 100), -INT8_C(  32), -INT8_C(  12), -INT8_C(  40), -INT8_C(  64),  INT8_C( 102),  INT8_C(  62) } }
  };

  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c[8];
  } test_vec_s16[] = {
    { {  INT32_C(   226421181),  INT32_C(  1138211133), -INT32_C(   497387112),  INT32_C(  1863198442) },
      { -INT16_C( 31342),  INT16_C(   719),  INT16_C( 18790), -INT16_C( 32516), -INT16_C( 31970),  INT16_C(  2254), -INT16_C( 31850),  INT16_C( 19263) },
      {  INT16_C(  6168),  INT16_C( 30906),  INT16_C( 18789), -INT16_C(  3510), -INT16_C( 12328),  INT16_C( 13774),  INT16_C(  1294), -INT16_C( 10311) } },
    { {  INT32_C(     3254514),  INT32_C(   448093867),  INT32_C(  1115108952),  INT32_C(  1159132052) },
      { -INT16_C(  9690),  INT16_C(  3369),  INT16_C( 32455),  INT16_C( 29888),  INT16_C( 23109),  INT16_C(  2708),  INT16_C(  3160),  INT16_C(  2386) },
      { -INT16_C(  6214), -INT16_C( 11010), -INT16_C( 25429), -INT16_C( 11225),  INT16_C( 18500), -INT16_C(  5122),  INT16_C( 22509),  INT16_C( 12883) } },
    { {  INT32_C(   949075109), -INT32_C(  2063577581), -INT32_C(   600190793),  INT32_C(   409686874) },
      {  INT16_C( 15651), -INT16_C( 17626),  INT16_C( 23554),  INT16_C( 16222), -INT16_C( 32159),  INT16_C(    78), -INT16_C( 24888),  INT16_C( 21724) },
      { -INT16_C( 14498), -INT16_C( 32014),  INT16_C( 13149), -INT16_C(  8335),  INT16_C( 23772), -INT16_C( 11043),  INT16_C(  1486),  INT16_C(    78) } },
    { {  INT32_C(  1668793723), -INT32_C(   216051287), -INT32_C(   496032523),  INT32_C(  1162607957) },
      { -INT16_C( 29954), -INT16_C(   371), -INT16_C( 28199),  INT16_C(  3348),  INT16_C( 27098), -INT16_C(   256), -INT16_C( 29927),  INT16_C( 15279) },
      {  INT16_C( 16777), -INT16_C(  7379),  INT16_C( 27454), -INT16_C(  7076),  INT16_C( 13100),  INT16_C(  5837), -INT16_C( 26166),  INT16_C(  2328) } },
    { { -INT32_C(   990372613),  INT32_C(  1114119320), -INT32_C(  2125372182),  INT32_C(  1549119940) },
      { -INT16_C( 24345), -INT16_C( 19846), -INT16_C( 17351), -INT16_C( 17505), -INT16_C( 18378), -INT16_C(  3957),  INT16_C( 11620),  INT16_C(  9416) },
      {  INT16_C(  9579),  INT16_C( 26151),  INT16_C( 16459),  INT16_C( 12895), -INT16_C( 31750), -INT16_C( 12168), -INT16_C( 13826), -INT16_C( 24627) } },
    { { -INT32_C(  1709604000),  INT32_C(   712860463),  INT32_C(  1372391525), -INT32_C(  1307005596) },
      { -INT16_C(  6937),  INT16_C( 26240), -INT16_C( 31493), -INT16_C(  7353), -INT16_C( 29625), -INT16_C(  6422), -INT16_C( 10985), -INT16_C( 31212) },
      { -INT16_C( 14511), -INT16_C( 19749),  INT16_C( 27408),  INT16_C( 17402),  INT16_C(  2888),  INT16_C( 23306), -INT16_C(  3831),  INT16_C( 31795) } },
    { { -INT32_C(  1411174042), -INT32_C(  2000947763),  INT32_C(  2024971772),  INT32_C(  1732815105) },
      {  INT16_C(  1029),  INT16_C( 20277), -INT16_C( 18590), -INT16_C( 13052), -INT16_C( 31793),  INT16_C(  9559),  INT16_C( 21909),  INT16_C(  4309) },
      { -INT16_C( 30690), -INT16_C(  1606), -INT16_C( 31302),  INT16_C( 21394), -INT16_C(  5421),  INT16_C( 11075),  INT16_C(  6091),  INT16_C(  2388) } },
    { {  INT32_C(    13244945), -INT32_C(  1680546174),  INT32_C(  1924549988), -INT32_C(   796760506) },
      {  INT16_C(  3421),  INT16_C( 25353),  INT16_C( 30289),  INT16_C( 19657), -INT16_C( 29266), -INT16_C( 12222),  INT16_C(  3105),  INT16_C( 13728) },
      { -INT16_C( 19530),  INT16_C( 32258),  INT16_C( 14049), -INT16_C(  7833), -INT16_C( 21237),  INT16_C( 26723), -INT16_C( 32427),  INT16_C(  4786) } }
  };

static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c[4];
  } test_vec_s32[] = {
    { {  INT64_C( 2915166466627834221),  INT64_C( 5745679196560508218) },
      { -INT32_C(  1483880387), -INT32_C(  1947963582),  INT32_C(  1160155774),  INT32_C(   821657332) },
      {  INT32_C(  1114479213),  INT32_C(   564949781),  INT32_C(   720978056), -INT32_C(   334441438) } },
    { { -INT64_C( 7921611883273376940), -INT64_C( 7187935984936560306) },
      { -INT32_C(  1610521037), -INT32_C(   981851402),  INT32_C(   641720240),  INT32_C(  1703640480) },
      { -INT32_C(   583005073),  INT32_C(  1421395485),  INT32_C(  1770231297), -INT32_C(    52053374) } },
    { { -INT64_C( 3041822665784953562),  INT64_C( 8092871009053080171) },
      { -INT32_C(   112231647), -INT32_C(   417452059),  INT32_C(   219438125),  INT32_C(  1056562338) },
      { -INT32_C(  2068771808),  INT32_C(   324314366), -INT32_C(  1779028556), -INT32_C(  1235280570) } },
    { {  INT64_C( 8173720799436010113), -INT64_C( 6241723329292239466) },
      {  INT32_C(  1381645385),  INT32_C(   512603488), -INT32_C(   303655325),  INT32_C(  1716497717) },
      {  INT32_C(  1034607746),  INT32_C(  2099432371), -INT32_C(   703048367), -INT32_C(    83368280) } },
    { {  INT64_C( 4942148586723404023), -INT64_C( 3462896659542466611) },
      {  INT32_C(   900142418),  INT32_C(  1400552059),  INT32_C(   452104157),  INT32_C(  2031028834) },
      {  INT32_C(   971852682),  INT32_C(  1529262249), -INT32_C(    21019292), -INT32_C(   218082964) } },
    { {  INT64_C( 5539802348058867643),  INT64_C(  647580112226511170) },
      {  INT32_C(  1097629260), -INT32_C(  1803903313),  INT32_C(   127228239),  INT32_C(   517172557) },
      {  INT32_C(  1686986110),  INT32_C(   660863217),  INT32_C(   719584560),  INT32_C(  1105444928) } },
    { {  INT64_C( 6000222111146278222),  INT64_C( 9010014347644521997) },
      {  INT32_C(  2062362548),  INT32_C(  1662295601), -INT32_C(  1538423779), -INT32_C(  2003266379) },
      {  INT32_C(   382283333),  INT32_C(   110885684),  INT32_C(     9565715), -INT32_C(  1304942252) } },
    { { -INT64_C( 8033077123805101528),  INT64_C( 2655543301238595171) },
      { -INT32_C(   968857237), -INT32_C(   119447535),  INT32_C(  1955418215),  INT32_C(  1821699263) },
      { -INT32_C(   130076489), -INT32_C(  1440131234), -INT32_C(  1396991908),  INT32_C(  1367606070) } }
  };

static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint8_t c[16];
  } test_vec_u8[] = {
    { { UINT16_C(64346), UINT16_C(29555), UINT16_C(50039), UINT16_C(10425), UINT16_C(18752), UINT16_C(16639), UINT16_C(24310), UINT16_C(64169) },
      { UINT8_C(176), UINT8_C( 10), UINT8_C(107), UINT8_C(154), UINT8_C( 10), UINT8_C(137), UINT8_C(205), UINT8_C(108),
        UINT8_C(132), UINT8_C(176), UINT8_C(122), UINT8_C( 69), UINT8_C(239), UINT8_C(144), UINT8_C(187), UINT8_C( 89) },
      { UINT8_C(235), UINT8_C(170), UINT8_C(122), UINT8_C( 15), UINT8_C(  6), UINT8_C(139), UINT8_C(243), UINT8_C( 33),
        UINT8_C(164), UINT8_C(129), UINT8_C(228), UINT8_C(125), UINT8_C(226), UINT8_C(200), UINT8_C(  0), UINT8_C(230) } },
    { { UINT16_C( 2351), UINT16_C(47336), UINT16_C(51427), UINT16_C(42239), UINT16_C(24210), UINT16_C( 2480), UINT16_C( 2528), UINT16_C(43289) },
      { UINT8_C( 20), UINT8_C( 66), UINT8_C(215), UINT8_C(205), UINT8_C( 22), UINT8_C(101), UINT8_C(119), UINT8_C(206),
        UINT8_C(  5), UINT8_C( 25), UINT8_C(123), UINT8_C(151), UINT8_C(102), UINT8_C(202), UINT8_C(207), UINT8_C(134) },
      { UINT8_C(123), UINT8_C(139), UINT8_C(228), UINT8_C(251), UINT8_C(147), UINT8_C(159), UINT8_C(127), UINT8_C(143),
        UINT8_C(154), UINT8_C(152), UINT8_C(159), UINT8_C( 48), UINT8_C( 13), UINT8_C(253), UINT8_C(220), UINT8_C(230) } },
    { { UINT16_C(38342), UINT16_C(35974), UINT16_C(44661), UINT16_C(20792), UINT16_C(28383), UINT16_C(33051), UINT16_C(35044), UINT16_C(38315) },
      { UINT8_C(103), UINT8_C( 24), UINT8_C( 43), UINT8_C(155), UINT8_C(185), UINT8_C(150), UINT8_C(171), UINT8_C( 42),
        UINT8_C( 43), UINT8_C( 23), UINT8_C(163), UINT8_C(183), UINT8_C( 86), UINT8_C( 44), UINT8_C( 24), UINT8_C(  5) },
      { UINT8_C(205), UINT8_C(132), UINT8_C(  9), UINT8_C( 88), UINT8_C( 33), UINT8_C(216), UINT8_C( 29), UINT8_C(215),
        UINT8_C( 90), UINT8_C(231), UINT8_C(251), UINT8_C(234), UINT8_C(185), UINT8_C(203), UINT8_C( 46), UINT8_C(199) } },
    { { UINT16_C(59566), UINT16_C(21175), UINT16_C( 8229), UINT16_C(35312), UINT16_C(41064), UINT16_C( 3714), UINT16_C(12146), UINT16_C(25053) },
      { UINT8_C(170), UINT8_C(  1), UINT8_C(117), UINT8_C(214), UINT8_C( 11), UINT8_C(207), UINT8_C(243), UINT8_C(114),
        UINT8_C(224), UINT8_C(184), UINT8_C(  2), UINT8_C(117), UINT8_C(185), UINT8_C( 40), UINT8_C(173), UINT8_C( 98) },
      { UINT8_C( 80), UINT8_C(110), UINT8_C( 61), UINT8_C( 81), UINT8_C( 23), UINT8_C(126), UINT8_C( 53), UINT8_C( 46),
        UINT8_C( 44), UINT8_C( 72), UINT8_C(184), UINT8_C(216), UINT8_C(242), UINT8_C( 33), UINT8_C(110), UINT8_C(206) } },
    { { UINT16_C( 7028), UINT16_C(50052), UINT16_C(24787), UINT16_C(60246), UINT16_C(43202), UINT16_C(61591), UINT16_C( 9390), UINT16_C(53219) },
      { UINT8_C(241), UINT8_C(213), UINT8_C(190), UINT8_C( 59), UINT8_C(124), UINT8_C(162), UINT8_C( 75), UINT8_C( 96),
        UINT8_C( 39), UINT8_C(186), UINT8_C(201), UINT8_C(153), UINT8_C( 58), UINT8_C( 64), UINT8_C(105), UINT8_C(179) },
      { UINT8_C(181), UINT8_C(  1), UINT8_C(158), UINT8_C( 99), UINT8_C(132), UINT8_C(159), UINT8_C(167), UINT8_C(152),
        UINT8_C(212), UINT8_C(217), UINT8_C(107), UINT8_C(133), UINT8_C(215), UINT8_C( 97), UINT8_C(157), UINT8_C( 54) } },
    { { UINT16_C(36408), UINT16_C( 5391), UINT16_C( 6448), UINT16_C(32090), UINT16_C(32759), UINT16_C(29575), UINT16_C(38276), UINT16_C( 7415) },
      { UINT8_C( 71), UINT8_C(  6), UINT8_C(235), UINT8_C(251), UINT8_C( 86), UINT8_C( 76), UINT8_C(241), UINT8_C( 55),
        UINT8_C( 10), UINT8_C(139), UINT8_C( 73), UINT8_C(247), UINT8_C(103), UINT8_C(186), UINT8_C(106), UINT8_C( 15) },
      { UINT8_C( 44), UINT8_C(210), UINT8_C(109), UINT8_C( 64), UINT8_C( 53), UINT8_C(242), UINT8_C( 78), UINT8_C( 85),
        UINT8_C( 77), UINT8_C( 64), UINT8_C(106), UINT8_C(212), UINT8_C(216), UINT8_C(154), UINT8_C(249), UINT8_C(211) } },
    { { UINT16_C(43317), UINT16_C(18016), UINT16_C(14696), UINT16_C(49117), UINT16_C(58134), UINT16_C(53988), UINT16_C(29438), UINT16_C(48202) },
      { UINT8_C(146), UINT8_C( 41), UINT8_C(  8), UINT8_C(111), UINT8_C(247), UINT8_C(157), UINT8_C( 72), UINT8_C(123),
        UINT8_C(  5), UINT8_C( 16), UINT8_C(213), UINT8_C( 50), UINT8_C( 16), UINT8_C(226), UINT8_C( 55), UINT8_C(119) },
      { UINT8_C(149), UINT8_C(157), UINT8_C(203), UINT8_C(234), UINT8_C(129), UINT8_C(179), UINT8_C(160), UINT8_C( 54),
        UINT8_C(  8), UINT8_C(179), UINT8_C(166), UINT8_C(163), UINT8_C( 44), UINT8_C( 84), UINT8_C( 90), UINT8_C( 27) } },
    { { UINT16_C(61515), UINT16_C(39056), UINT16_C(55943), UINT16_C(40713), UINT16_C(45128), UINT16_C(49771), UINT16_C(48594), UINT16_C(35983) },
      { UINT8_C(107), UINT8_C(202), UINT8_C(226), UINT8_C(239), UINT8_C(205), UINT8_C(227), UINT8_C(227), UINT8_C(139),
        UINT8_C(233), UINT8_C( 60), UINT8_C(125), UINT8_C( 47), UINT8_C(239), UINT8_C(220), UINT8_C(129), UINT8_C( 32) },
      { UINT8_C(177), UINT8_C(222), UINT8_C(199), UINT8_C(243), UINT8_C(219), UINT8_C(152), UINT8_C( 99), UINT8_C(228),
        UINT8_C(169), UINT8_C(214), UINT8_C( 88), UINT8_C( 39), UINT8_C(145), UINT8_C(219), UINT8_C( 33), UINT8_C(153) } }
  };

static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t c[8];
  } test_vec_u16[] = {
    { { UINT32_C( 911563394), UINT32_C(1756969370), UINT32_C(2846423643), UINT32_C(1730436141) },
      { UINT16_C(36345), UINT16_C(58889), UINT16_C(57098), UINT16_C(12963), UINT16_C(29249), UINT16_C(12193), UINT16_C(63624), UINT16_C(14204) },
      { UINT16_C(46668), UINT16_C(60372), UINT16_C(52759), UINT16_C( 2951), UINT16_C(25145), UINT16_C(59270), UINT16_C( 9013), UINT16_C(52938) } },
    { { UINT32_C(  81984652), UINT32_C(2399319178), UINT32_C(2239034576), UINT32_C( 768638905) },
      { UINT16_C(38337), UINT16_C(   36), UINT16_C(52499), UINT16_C( 6390), UINT16_C(45358), UINT16_C(38756), UINT16_C(41021), UINT16_C( 2006) },
      { UINT16_C( 6247), UINT16_C(64147), UINT16_C(65393), UINT16_C(30228), UINT16_C(37593), UINT16_C(26993), UINT16_C(12524), UINT16_C(32537) } },
    { { UINT32_C(2704014140), UINT32_C(1960761016), UINT32_C(2001578844), UINT32_C( 841649631) },
      { UINT16_C(16505), UINT16_C(36776), UINT16_C(29871), UINT16_C(10800), UINT16_C(37058), UINT16_C(26366), UINT16_C(50861), UINT16_C(36174) },
      { UINT16_C(17752), UINT16_C(43516), UINT16_C(26445), UINT16_C( 5942), UINT16_C(25331), UINT16_C(36051), UINT16_C( 4246), UINT16_C(28891) } },
    { { UINT32_C(2441137154), UINT32_C( 250115151), UINT32_C(  93357293), UINT32_C( 546217032) },
      { UINT16_C(10449), UINT16_C( 6630), UINT16_C(16880), UINT16_C(58624), UINT16_C(  211), UINT16_C(21473), UINT16_C(58176), UINT16_C(31710) },
      { UINT16_C(38385), UINT16_C(53472), UINT16_C(63667), UINT16_C(64364), UINT16_C(39902), UINT16_C(35068), UINT16_C(22218), UINT16_C(34383) } },
    { { UINT32_C(2391129950), UINT32_C(2184891478), UINT32_C(4270426664), UINT32_C( 968326552) },
      { UINT16_C(30270), UINT16_C( 4987), UINT16_C(29652), UINT16_C(38401), UINT16_C(57938), UINT16_C(39875), UINT16_C(34299), UINT16_C(42380) },
      { UINT16_C(35476), UINT16_C(46540), UINT16_C(33163), UINT16_C(10184), UINT16_C(42505), UINT16_C(41937), UINT16_C(13236), UINT16_C(22308) } },
    { { UINT32_C( 260560463), UINT32_C(2775104125), UINT32_C( 241338976), UINT32_C( 351554401) },
      { UINT16_C(30653), UINT16_C(50707), UINT16_C(19115), UINT16_C(31846), UINT16_C(24596), UINT16_C(30591), UINT16_C(24455), UINT16_C(55757) },
      { UINT16_C(11854), UINT16_C(22597), UINT16_C(60045), UINT16_C(25682), UINT16_C(11928), UINT16_C(34974), UINT16_C( 1594), UINT16_C(11283) } },
    { { UINT32_C(4113165246), UINT32_C(1804988581), UINT32_C(  49017871), UINT32_C(3052570971) },
      { UINT16_C(35983), UINT16_C(24722), UINT16_C(20017), UINT16_C(57033), UINT16_C( 6684), UINT16_C(16595), UINT16_C(62075), UINT16_C( 9352) },
      { UINT16_C(49647), UINT16_C(59486), UINT16_C(31477), UINT16_C(62597), UINT16_C(36742), UINT16_C(22218), UINT16_C(35920), UINT16_C(26137) } },
    { { UINT32_C(1668751080), UINT32_C(1117996069), UINT32_C(2940506310), UINT32_C( 573427663) },
      { UINT16_C(22523), UINT16_C(13204), UINT16_C(38758), UINT16_C( 2058), UINT16_C( 6758), UINT16_C(17149), UINT16_C(47579), UINT16_C(33979) },
      { UINT16_C(45072), UINT16_C(25777), UINT16_C( 9457), UINT16_C(14827), UINT16_C( 3647), UINT16_C(19045), UINT16_C(35733), UINT16_C(21829) } }
  };

static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t c[4];
  } test_vec_u32[] = {
    { { UINT64_C( 6738231450799804352), UINT64_C( 6481524578867739547) },
      { UINT32_C( 574897153), UINT32_C( 961619494), UINT32_C( 908826145), UINT32_C( 112124635) },
      { UINT32_C(1806292778), UINT32_C(1120790214), UINT32_C( 714399666), UINT32_C(1999443232) } },
    { { UINT64_C(16184325855513110866), UINT64_C(13045812537069334546) },
      { UINT32_C( 849031184), UINT32_C(1999654006), UINT32_C(1758821749), UINT32_C(1288804311) },
      { UINT32_C( 859050132), UINT32_C(1175072695), UINT32_C(1238759141), UINT32_C( 687362708) } },
    { { UINT64_C(  237135280280056344), UINT64_C(13687342079162670982) },
      { UINT32_C(1324534710), UINT32_C(1440225684), UINT32_C(2447889077), UINT32_C(2217595274) },
      { UINT32_C(3032945807), UINT32_C( 167859877), UINT32_C(1109501442), UINT32_C(3087193191) } },
    { { UINT64_C( 2347422534454505051), UINT64_C( 7401954084738386951) },
      { UINT32_C( 921743176), UINT32_C(2691619005), UINT32_C(1338691612), UINT32_C(3396646018) },
      { UINT32_C(4123499327), UINT32_C( 916003952), UINT32_C(1592593380), UINT32_C(4079320429) } },
    { { UINT64_C(11875538373947263358), UINT64_C(13291135113222454971) },
      { UINT32_C(2614704786), UINT32_C(4169242806), UINT32_C(1481694457), UINT32_C(4087970256) },
      { UINT32_C(2353255596), UINT32_C(2473276423), UINT32_C(2667789337), UINT32_C( 277933204) } },
    { { UINT64_C(17692578922103901268), UINT64_C(16382011726574516660) },
      { UINT32_C(1614117745), UINT32_C(1603453446), UINT32_C(1332691808), UINT32_C(3329026797) },
      { UINT32_C(1259808439), UINT32_C( 939580999), UINT32_C(2201440100), UINT32_C( 256735212) } },
    { { UINT64_C( 4861400312709325929), UINT64_C(14080433678315832139) },
      { UINT32_C( 232161403), UINT32_C(2713696250), UINT32_C(1223017044), UINT32_C(2782551785) },
      { UINT32_C( 291518222), UINT32_C(2620230786), UINT32_C(1694181566), UINT32_C(2152706776) } },
    { { UINT64_C( 4579760789896459082), UINT64_C(14751223259073443307) },
      { UINT32_C(1949688724), UINT32_C(3180101467), UINT32_C(4222738281), UINT32_C(2534427848) },
      { UINT32_C(3461433116), UINT32_C(2693895381), UINT32_C(2479624651), UINT32_C(3140125325) } }
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
        int16x8_t a = vld1q_s16(test_vec_s8[i].a);
        // printf("test:\n");
        // for (int i = 0; i < 8; i++)
        // {
        //     printf("%hd, ", a[i]);
        // }
        // printf("\ntest end\n");
        int8x16_t b = vld1q_s8(test_vec_s8[i].b);
        int8x16_t c = vld1q_s8(test_vec_s8[i].c);
        int16x8_t rst = vabal_high_s8(a, b, c);
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
        int32x4_t a = vld1q_s32(test_vec_s16[i].a);
        int16x8_t b = vld1q_s16(test_vec_s16[i].b);
        int16x8_t c = vld1q_s16(test_vec_s16[i].c);
        int32x4_t rst = vabal_high_s16(a, b, c);

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
        int64x2_t a = vld1q_s64(test_vec_s32[i].a);
        int32x4_t b = vld1q_s32(test_vec_s32[i].b);
        int32x4_t c = vld1q_s32(test_vec_s32[i].c);
        int64x2_t rst = vabal_high_s32(a, b, c);

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
        uint16x8_t a = vld1q_u16(test_vec_u8[i].a);
        uint8x16_t b = vld1q_u8(test_vec_u8[i].b);
        uint8x16_t c = vld1q_u8(test_vec_u8[i].c);
        uint16x8_t rst = vabal_high_u8(a, b, c);

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
        uint32x4_t a = vld1q_u32(test_vec_u16[i].a);
        uint16x8_t b = vld1q_u16(test_vec_u16[i].b);
        uint16x8_t c = vld1q_u16(test_vec_u16[i].c);
        uint32x4_t rst = vabal_high_u16(a, b, c);

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
        uint64x2_t a = vld1q_u64(test_vec_u32[i].a);
        uint32x4_t b = vld1q_u32(test_vec_u32[i].b);
        uint32x4_t c = vld1q_u32(test_vec_u32[i].c);
        uint64x2_t rst = vabal_high_u32(a, b, c);

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_u64(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}
