#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int16_t a[8];
    int8_t b[8];
    int8_t c[8];
  } test_vec_s8[] = {
    { { -INT16_C( 32483),  INT16_C(  8488),  INT16_C( 17800),  INT16_C( 11994),  INT16_C( 28479), -INT16_C(   926), -INT16_C( 25595),  INT16_C( 21103) },
      {  INT8_C(  69),  INT8_C(  91),  INT8_C(  67), -INT8_C(  35), -INT8_C(  77), -INT8_C( 103),  INT8_C(  20),  INT8_C( 104) },
      {  INT8_C(  10), -INT8_C(  79), -INT8_C(  70), -INT8_C(  61), -INT8_C( 116),  INT8_C( 125), -INT8_C(   6), -INT8_C(  69) } },
    { {  INT16_C( 18497),  INT16_C(  3389),  INT16_C( 15333),  INT16_C(  7813),  INT16_C(  4839),  INT16_C( 11151), -INT16_C( 22483),  INT16_C( 17984) },
      { -INT8_C(  52), -INT8_C(  73),  INT8_C( 116), -INT8_C(  74), -INT8_C(  83),  INT8_C(   7), -INT8_C( 117), -INT8_C(  14) },
      {  INT8_C( 124), -INT8_C(  89), -INT8_C(  40), -INT8_C(  49), -INT8_C( 115), -INT8_C(  52),  INT8_C( 120),  INT8_C(  26) } },
    { { -INT16_C(  9283), -INT16_C( 29756),  INT16_C( 17945),  INT16_C( 22005),  INT16_C( 24940), -INT16_C(  7904), -INT16_C( 27388),  INT16_C( 13372) },
      {  INT8_C(  99),  INT8_C( 100),  INT8_C(  31),  INT8_C(  68),  INT8_C(  38),  INT8_C(  12),  INT8_C(  63),  INT8_C(  64) },
      { -INT8_C(  59),  INT8_C(  66), -INT8_C(  38), -INT8_C(  17), -INT8_C(   8), -INT8_C(  23),  INT8_C(  97), -INT8_C(  35) } },
    { { -INT16_C(  3646), -INT16_C( 30107),  INT16_C(  3015),  INT16_C( 13523), -INT16_C( 16438), -INT16_C( 21129),  INT16_C(  2393), -INT16_C(  2729) },
      { -INT8_C(  85),  INT8_C(  38),  INT8_C( 109),  INT8_C( 104), -INT8_C( 115), -INT8_C(  50),  INT8_C(  62), -INT8_C( 119) },
      {  INT8_C(  25),  INT8_C(  79),  INT8_C(  49), -INT8_C(  47),  INT8_C(  45), -INT8_C(  90), -INT8_C(   9),  INT8_C(   7) } },
    { {  INT16_C( 28585),  INT16_C( 19546),  INT16_C( 24042),  INT16_C(  2658),  INT16_C(  9255), -INT16_C(  1642), -INT16_C(  9653),  INT16_C( 11740) },
      { -INT8_C(  38),  INT8_C( 115),  INT8_C(  29), -INT8_C( 110),  INT8_C(  11),  INT8_C(  83), -INT8_C(  88), -INT8_C(  37) },
      {  INT8_C(  35),  INT8_C(  20), -INT8_C(  49), -INT8_C( 103),  INT8_C(  28),  INT8_C(  20),  INT8_C(  44), -INT8_C(  75) } },
    { {  INT16_C( 11918), -INT16_C( 25541),  INT16_C( 24149), -INT16_C( 21463), -INT16_C( 22741), -INT16_C(   860), -INT16_C(  4471), -INT16_C( 23582) },
      { -INT8_C(  38), -INT8_C(  72), -INT8_C(  47),  INT8_C( 117),  INT8_C( 124),  INT8_C(  39), -INT8_C(  39),  INT8_C(  55) },
      { -INT8_C(  30),  INT8_C(  88),  INT8_C(  55),  INT8_C(  80), -INT8_C(   1), -INT8_C(  21), -INT8_C( 107), -INT8_C(  16) } },
    { { -INT16_C( 16656),  INT16_C(  1227), -INT16_C( 21456),  INT16_C(  3237),  INT16_C(    96), -INT16_C( 19070),  INT16_C( 10381), -INT16_C( 25416) },
      {  INT8_C( 103), -INT8_C(  99),  INT8_C(  96), -INT8_C(  62),  INT8_C( 112),  INT8_C(   0), -INT8_C( 105), -INT8_C(  91) },
      { -INT8_C( 125),  INT8_C( 105), -INT8_C( 117),  INT8_C(  99),  INT8_C(  30), -INT8_C(  14),  INT8_C(  86), -INT8_C( 120) } },
    { {  INT16_C( 12623),  INT16_C(  1478),  INT16_C( 32626), -INT16_C( 12815),  INT16_C(  4754), -INT16_C(  9898),  INT16_C( 19417),  INT16_C( 10063) },
      {  INT8_C(  44),  INT8_C(  77),  INT8_C(  33), -INT8_C(  43),  INT8_C(  41),  INT8_C( 100),  INT8_C(  66),  INT8_C(  74) },
      {  INT8_C(  69),  INT8_C(  30), -INT8_C( 105),  INT8_C(  19), -INT8_C( 119),  INT8_C(  94),  INT8_C(  12), -INT8_C(  25) } }
  };

static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c[4];
  } test_vec_s16[] = {
    { {  INT32_C(  1253236169), -INT32_C(   612575642), -INT32_C(   770020057),  INT32_C(  2091834424) },
      { -INT16_C( 17437),  INT16_C( 30012),  INT16_C( 21656),  INT16_C( 32256) },
      { -INT16_C(  7598), -INT16_C(  4378),  INT16_C( 16854), -INT16_C(  6464) } },
    { { -INT32_C(   542431816),  INT32_C(    28285475), -INT32_C(  1339566458),  INT32_C(  1297879037) },
      { -INT16_C(  5777), -INT16_C( 31757), -INT16_C(  5541), -INT16_C(  7444) },
      { -INT16_C( 18527),  INT16_C( 16839), -INT16_C(  5409), -INT16_C( 22829) } },
    { {  INT32_C(  1747925588),  INT32_C(  2074198798),  INT32_C(   499764846),  INT32_C(   550480188) },
      {  INT16_C( 12030), -INT16_C( 19467),  INT16_C(  1723),  INT16_C( 30018) },
      {  INT16_C( 15825), -INT16_C( 27550),  INT16_C( 19588),  INT16_C( 26094) } },
    { {  INT32_C(  1458563400), -INT32_C(  1849458346),  INT32_C(  1506285652), -INT32_C(  1612913140) },
      {  INT16_C( 31015),  INT16_C( 16553), -INT16_C(  4179), -INT16_C( 20846) },
      { -INT16_C( 18168),  INT16_C(  7363),  INT16_C( 26212),  INT16_C( 20971) } },
    { {  INT32_C(   496851292),  INT32_C(   730619248),  INT32_C(   754334407), -INT32_C(   199139388) },
      { -INT16_C( 25340), -INT16_C( 23426), -INT16_C(   566), -INT16_C( 29464) },
      {  INT16_C(  6609),  INT16_C( 12520), -INT16_C( 22629),  INT16_C( 26056) } },
    { {  INT32_C(  1824052487),  INT32_C(  1747543707), -INT32_C(   591328313),  INT32_C(   477623095) },
      { -INT16_C( 28330),  INT16_C( 20534),  INT16_C( 15697), -INT16_C( 20481) },
      { -INT16_C(  1028), -INT16_C( 15664),  INT16_C( 21638),  INT16_C( 13716) } },
    { {  INT32_C(  1599837205),  INT32_C(   825053272),  INT32_C(   616379176),  INT32_C(  1029483000) },
      { -INT16_C( 18277),  INT16_C( 23097),  INT16_C(  5671),  INT16_C( 29289) },
      { -INT16_C( 19593), -INT16_C( 10873), -INT16_C(  3718), -INT16_C( 12453) } },
    { { -INT32_C(  1207273403), -INT32_C(   784752404),  INT32_C(   724808429), -INT32_C(    43542641) },
      {  INT16_C( 10548),  INT16_C( 15838), -INT16_C(  3633), -INT16_C(  1850) },
      {  INT16_C( 20529), -INT16_C(  3783), -INT16_C( 24188), -INT16_C( 30955) } }
  };

static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c[2];
  } test_vec_s32[] = {
    { { -INT64_C( 8164237937416544801), -INT64_C( 2833103088083965272) },
      { -INT32_C(  2001013888),  INT32_C(  1239998062) },
      { -INT32_C(  1741052426), -INT32_C(   728395220) } },
    { {  INT64_C( 4136388466899113565),  INT64_C( 8375055668324245462) },
      { -INT32_C(  1762499594),  INT32_C(  1762147268) },
      { -INT32_C(  1072411570),  INT32_C(   611803690) } },
    { { -INT64_C( 4016012344647320575), -INT64_C(  399301388827393728) },
      {  INT32_C(  1183009355),  INT32_C(  1727157805) },
      {  INT32_C(  1184738136), -INT32_C(  1341423317) } },
    { { -INT64_C( 1440705433047225482),  INT64_C( 7751760218345288021) },
      { -INT32_C(  1349106295),  INT32_C(  1982995361) },
      {  INT32_C(  1727791019),  INT32_C(  1397136271) } },
    { { -INT64_C( 6572396932712509331), -INT64_C(  934721378000845174) },
      { -INT32_C(   725155792),  INT32_C(   155365804) },
      {  INT32_C(   750411060),  INT32_C(  1689451808) } },
    { { -INT64_C( 2813787126501922500),  INT64_C( 5037831440734475963) },
      {  INT32_C(  1585086036), -INT32_C(   491051152) },
      { -INT32_C(   204227822), -INT32_C(  2074740262) } },
    { { -INT64_C( 1683305550690644099), -INT64_C( 1554928862122411901) },
      {  INT32_C(  1378246587),  INT32_C(   696129188) },
      { -INT32_C(   759106698),  INT32_C(  2091273889) } },
    { {  INT64_C( 5369216416315455913), -INT64_C( 7042631195704111970) },
      { -INT32_C(  1029561352), -INT32_C(  2082060401) },
      {  INT32_C(   411553406),  INT32_C(   242716929) } }
  };

static const struct {
    uint16_t a[8];
    uint8_t b[8];
    uint8_t c[8];
  } test_vec_u8[] = {
    { { UINT16_C( 1465), UINT16_C(11992), UINT16_C(40921), UINT16_C( 6764), UINT16_C(  840), UINT16_C(38208), UINT16_C(22431), UINT16_C(40988) },
      { UINT8_C(144), UINT8_C(117), UINT8_C(116), UINT8_C(137), UINT8_C(  8), UINT8_C( 93), UINT8_C(247), UINT8_C( 42) },
      { UINT8_C( 25), UINT8_C(  3), UINT8_C(199), UINT8_C(190), UINT8_C(240), UINT8_C(139), UINT8_C(229), UINT8_C(205) } },
    { { UINT16_C(15295), UINT16_C( 9232), UINT16_C(29017), UINT16_C(45844), UINT16_C(57494), UINT16_C( 4330), UINT16_C(17974), UINT16_C( 2817) },
      { UINT8_C( 15), UINT8_C(111), UINT8_C( 31), UINT8_C(252), UINT8_C(115), UINT8_C(117), UINT8_C(133), UINT8_C(254) },
      { UINT8_C(221), UINT8_C( 70), UINT8_C(201), UINT8_C(223), UINT8_C(133), UINT8_C(167), UINT8_C( 69), UINT8_C(242) } },
    { { UINT16_C(54669), UINT16_C(52100), UINT16_C(59770), UINT16_C(17086), UINT16_C(50137), UINT16_C(18601), UINT16_C(26691), UINT16_C(11723) },
      { UINT8_C( 47), UINT8_C(219), UINT8_C(113), UINT8_C(164), UINT8_C(190), UINT8_C(210), UINT8_C(106), UINT8_C(160) },
      { UINT8_C(236), UINT8_C( 67), UINT8_C(141), UINT8_C( 48), UINT8_C(190), UINT8_C( 83), UINT8_C( 18), UINT8_C( 52) } },
    { { UINT16_C(17738), UINT16_C( 6517), UINT16_C(51714), UINT16_C(25061), UINT16_C(44282), UINT16_C(22666), UINT16_C(42732), UINT16_C(55699) },
      { UINT8_C(238), UINT8_C(131), UINT8_C(209), UINT8_C(242), UINT8_C(100), UINT8_C(126), UINT8_C(177), UINT8_C(135) },
      { UINT8_C(205), UINT8_C(176), UINT8_C(213), UINT8_C(114), UINT8_C( 55), UINT8_C(103), UINT8_C(219), UINT8_C(155) } },
    { { UINT16_C(47636), UINT16_C(26371), UINT16_C(37341), UINT16_C(43244), UINT16_C(50135), UINT16_C(18059), UINT16_C(41844), UINT16_C(49947) },
      { UINT8_C(178), UINT8_C(110), UINT8_C(142), UINT8_C(244), UINT8_C( 99), UINT8_C(244), UINT8_C(193), UINT8_C( 20) },
      { UINT8_C( 78), UINT8_C( 71), UINT8_C( 56), UINT8_C(233), UINT8_C(235), UINT8_C(143), UINT8_C( 50), UINT8_C( 87) } },
    { { UINT16_C(58783), UINT16_C(43262), UINT16_C(40863), UINT16_C(18126), UINT16_C(55973), UINT16_C(62750), UINT16_C(42880), UINT16_C(53054) },
      { UINT8_C( 98), UINT8_C( 42), UINT8_C( 43), UINT8_C( 14), UINT8_C( 66), UINT8_C(194), UINT8_C(145), UINT8_C(167) },
      { UINT8_C( 95), UINT8_C(215), UINT8_C( 45), UINT8_C(213), UINT8_C(244), UINT8_C(170), UINT8_C(154), UINT8_C(153) } },
    { { UINT16_C(50384), UINT16_C(40369), UINT16_C(23294), UINT16_C(38343), UINT16_C(64327), UINT16_C( 7361), UINT16_C(34379), UINT16_C(28001) },
      { UINT8_C(139), UINT8_C( 18), UINT8_C(173), UINT8_C(174), UINT8_C( 10), UINT8_C( 51), UINT8_C(208), UINT8_C(187) },
      { UINT8_C(242), UINT8_C( 65), UINT8_C( 25), UINT8_C(228), UINT8_C( 68), UINT8_C( 54), UINT8_C(112), UINT8_C(101) } },
    { { UINT16_C(24414), UINT16_C( 3504), UINT16_C(22868), UINT16_C(45831), UINT16_C(58291), UINT16_C(16005), UINT16_C(33264), UINT16_C(60379) },
      { UINT8_C(116), UINT8_C(147), UINT8_C(236), UINT8_C(  2), UINT8_C( 68), UINT8_C(243), UINT8_C( 25), UINT8_C(245) },
      { UINT8_C(215), UINT8_C(133), UINT8_C( 92), UINT8_C(170), UINT8_C(104), UINT8_C(177), UINT8_C(228), UINT8_C(105) } }
  };

static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t c[4];
  } test_vec_u16[] = {
    { { UINT32_C(4205288045), UINT32_C( 324765468), UINT32_C(2678035020), UINT32_C(3446222492) },
      { UINT16_C(29511), UINT16_C(44510), UINT16_C(46330), UINT16_C(15897) },
      { UINT16_C(50075), UINT16_C( 6499), UINT16_C( 1602), UINT16_C(54745) } },
    { { UINT32_C(3643534895), UINT32_C( 434129262), UINT32_C( 972410178), UINT32_C( 613901016) },
      { UINT16_C( 5413), UINT16_C(33254), UINT16_C(54963), UINT16_C(55750) },
      { UINT16_C(17255), UINT16_C(61875), UINT16_C(60107), UINT16_C(12001) } },
    { { UINT32_C(3296869248), UINT32_C(2897126015), UINT32_C(3031278061), UINT32_C(3778089147) },
      { UINT16_C(49740), UINT16_C(12322), UINT16_C( 3441), UINT16_C(30343) },
      { UINT16_C(32222), UINT16_C(15606), UINT16_C(19150), UINT16_C(10014) } },
    { { UINT32_C(3010757766), UINT32_C(3431423774), UINT32_C(1505488433), UINT32_C( 766588465) },
      { UINT16_C(60465), UINT16_C( 1465), UINT16_C( 1457), UINT16_C(19299) },
      { UINT16_C( 6903), UINT16_C(49932), UINT16_C(44454), UINT16_C(30012) } },
    { { UINT32_C(2971319371), UINT32_C( 730084914), UINT32_C( 191753428), UINT32_C(3182214454) },
      { UINT16_C(30876), UINT16_C(39465), UINT16_C( 2148), UINT16_C(11058) },
      { UINT16_C(65249), UINT16_C(33047), UINT16_C(39166), UINT16_C(42325) } },
    { { UINT32_C( 363563103), UINT32_C(3217354810), UINT32_C(1023257826), UINT32_C( 742286099) },
      { UINT16_C(65227), UINT16_C(35989), UINT16_C(43251), UINT16_C(38598) },
      { UINT16_C(20189), UINT16_C( 7049), UINT16_C(64396), UINT16_C(62437) } },
    { { UINT32_C(2974419061), UINT32_C(1545309896), UINT32_C(3776620042), UINT32_C(1316921501) },
      { UINT16_C( 5263), UINT16_C(13331), UINT16_C(24891), UINT16_C(55070) },
      { UINT16_C(29726), UINT16_C(21812), UINT16_C(37077), UINT16_C( 8373) } },
    { { UINT32_C( 265525761), UINT32_C(1203597825), UINT32_C(1836661241), UINT32_C(2246413171) },
      { UINT16_C(37732), UINT16_C(23033), UINT16_C(16264), UINT16_C( 5521) },
      { UINT16_C( 9892), UINT16_C(35668), UINT16_C(17633), UINT16_C(18125) } }
  };

static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t c[2];
  } test_vec_u32[] = {
    { { UINT64_C(14839216846299439828), UINT64_C( 1928313858148217787) },
      { UINT32_C(3929005465), UINT32_C(1744537494) },
      { UINT32_C( 614558495), UINT32_C(2992479236) } },
    { { UINT64_C(15614613037905760188), UINT64_C(10566368195978221593) },
      { UINT32_C(3010862948), UINT32_C(4059060879) },
      { UINT32_C( 123512007), UINT32_C(3064733332) } },
    { { UINT64_C( 9904846050069865250), UINT64_C(  127645449895273972) },
      { UINT32_C( 264085256), UINT32_C(4125449225) },
      { UINT32_C( 375164736), UINT32_C(2131473068) } },
    { { UINT64_C(14537713036092569001), UINT64_C( 7387573916644547241) },
      { UINT32_C(2792094445), UINT32_C(3898497538) },
      { UINT32_C(2635877747), UINT32_C(4038790628) } },
    { { UINT64_C(16204350741814066120), UINT64_C(18142840733880204391) },
      { UINT32_C( 447573699), UINT32_C(2367812576) },
      { UINT32_C(3486083439), UINT32_C(1944326680) } },
    { { UINT64_C( 1125072415389339244), UINT64_C(10263514267044060818) },
      { UINT32_C(3301319068), UINT32_C( 123680878) },
      { UINT32_C( 928243782), UINT32_C(3480829469) } },
    { { UINT64_C( 2440768118846976405), UINT64_C(15546588895907948066) },
      { UINT32_C(1717331211), UINT32_C(4007941595) },
      { UINT32_C( 829760491), UINT32_C(  36636803) } },
    { { UINT64_C(  243180530615014899), UINT64_C(14976861665867584254) },
      { UINT32_C(3821534277), UINT32_C(1766079158) },
      { UINT32_C(1590304529), UINT32_C( 325536343) } }
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
        int8x8_t b = vld1_s8(test_vec_s8[i].b);
        int8x8_t c = vld1_s8(test_vec_s8[i].c);
        int16x8_t rst = vabal_s8(a, b, c);
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
        int16x4_t b = vld1_s16(test_vec_s16[i].b);
        int16x4_t c = vld1_s16(test_vec_s16[i].c);
        int32x4_t rst = vabal_s16(a, b, c);

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
        int32x2_t b = vld1_s32(test_vec_s32[i].b);
        int32x2_t c = vld1_s32(test_vec_s32[i].c);
        int64x2_t rst = vabal_s32(a, b, c);

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
        uint8x8_t b = vld1_u8(test_vec_u8[i].b);
        uint8x8_t c = vld1_u8(test_vec_u8[i].c);
        uint16x8_t rst = vabal_u8(a, b, c);

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
        uint16x4_t b = vld1_u16(test_vec_u16[i].b);
        uint16x4_t c = vld1_u16(test_vec_u16[i].c);
        uint32x4_t rst = vabal_u16(a, b, c);

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
        uint32x2_t b = vld1_u32(test_vec_u32[i].b);
        uint32x2_t c = vld1_u32(test_vec_u32[i].c);
        uint64x2_t rst = vabal_u32(a, b, c);

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_u64(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}
