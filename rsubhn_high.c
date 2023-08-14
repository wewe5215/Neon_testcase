#include "print_output.h"
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();

static const struct {
    int16_t a[8];
    int16_t b[8];
    int8_t r[8];
  } test_vec_s16[] = {
    { { -INT16_C( 16675),  INT16_C(  7907), -INT16_C( 27180),  INT16_C( 10422),  INT16_C( 25187), -INT16_C( 31368),  INT16_C( 12335), -INT16_C( 14807) },
      { -INT16_C( 20962), -INT16_C( 31480),  INT16_C(  8022),  INT16_C(  4523),  INT16_C( 22350),  INT16_C(  6911), -INT16_C( 23656),  INT16_C( 11807) },
      { -INT8_C(  28),  INT8_C(  16),  INT8_C( 102), -INT8_C(  12), -INT8_C(  22),  INT8_C(  73), -INT8_C(  75),  INT8_C( 109) } },
    { { -INT16_C( 30284),  INT16_C(   544), -INT16_C(  1427),  INT16_C( 26869), -INT16_C( 25216),  INT16_C( 13560), -INT16_C(  5347), -INT16_C(  2626) },
      { -INT16_C( 20027),  INT16_C(   164), -INT16_C( 15807), -INT16_C(  9952),  INT16_C(  6885), -INT16_C( 14716),  INT16_C( 13640), -INT16_C( 14404) },
      {  INT8_C(  15), -INT8_C(   2), -INT8_C(  96),  INT8_C(  30),  INT8_C(  31), -INT8_C(  26),  INT8_C(  31),  INT8_C(  10) } },
    { { -INT16_C(   262), -INT16_C( 16820),  INT16_C( 14640), -INT16_C(  8635), -INT16_C( 19105),  INT16_C( 28000), -INT16_C( 30053),  INT16_C( 27689) },
      { -INT16_C( 15930),  INT16_C( 14067), -INT16_C( 10681), -INT16_C(  9698), -INT16_C(  3327), -INT16_C(  8949), -INT16_C( 10244), -INT16_C(  6568) },
      { -INT8_C( 127), -INT8_C(  42), -INT8_C(  94),  INT8_C(  62), -INT8_C( 127),  INT8_C(  31), -INT8_C(  56),  INT8_C(  16) } },
    { { -INT16_C( 24235),  INT16_C(  5896), -INT16_C( 20346),  INT16_C( 11351),  INT16_C( 22390),  INT16_C( 26217),  INT16_C(  9166), -INT16_C(  4091) },
      { -INT16_C( 27707),  INT16_C( 26138),  INT16_C( 21213), -INT16_C(  7804),  INT16_C( 22472), -INT16_C( 14372),  INT16_C(  9258), -INT16_C( 23204) },
      {  INT8_C(  24), -INT8_C(  48),  INT8_C(  63), -INT8_C(  80), -INT8_C( 121), -INT8_C(  32), -INT8_C( 106), -INT8_C( 113) } },
    { { -INT16_C(  7408), -INT16_C( 22553),  INT16_C( 14669),  INT16_C(  5275),  INT16_C(  2077),  INT16_C( 30015), -INT16_C(  8062),  INT16_C( 23731) },
      { -INT16_C( 20776), -INT16_C( 26133),  INT16_C( 25074),  INT16_C(  7503),  INT16_C( 15284), -INT16_C(  8697), -INT16_C( 25852), -INT16_C( 27375) },
      { -INT8_C(  12),  INT8_C( 104),  INT8_C(   5),  INT8_C(  53), -INT8_C(  64), -INT8_C(   4),  INT8_C(  61),  INT8_C(  39) } },
    { {  INT16_C( 32564), -INT16_C( 10576),  INT16_C( 29513),  INT16_C(  1797), -INT16_C( 15438),  INT16_C( 22178), -INT16_C( 20279), -INT16_C(   554) },
      {  INT16_C(   810),  INT16_C( 12365),  INT16_C(  7813),  INT16_C(  6811),  INT16_C(  9707), -INT16_C(  6076), -INT16_C( 16471), -INT16_C(  3163) },
      {  INT8_C( 121),  INT8_C(  46),  INT8_C( 115), -INT8_C(  40), -INT8_C(  16), -INT8_C(  49), -INT8_C(  99), -INT8_C(  65) } },
    { {  INT16_C(   747),  INT16_C( 15492), -INT16_C( 14014),  INT16_C( 23740), -INT16_C(  2353),  INT16_C(  4728),  INT16_C( 19693),  INT16_C( 11299) },
      { -INT16_C(  6850), -INT16_C(  4520), -INT16_C(  4594),  INT16_C( 17690),  INT16_C( 23677), -INT16_C( 15501), -INT16_C(  4271),  INT16_C( 23953) },
      {  INT8_C(  75),  INT8_C(  34), -INT8_C( 116),  INT8_C(  85),  INT8_C(  23),  INT8_C( 111),  INT8_C(  17),      INT8_MIN } },
    { {  INT16_C(  5801), -INT16_C( 14346), -INT16_C( 28227),  INT16_C( 26142),  INT16_C( 15321),  INT16_C( 32378), -INT16_C( 21636), -INT16_C(   352) },
      {  INT16_C( 26325),  INT16_C( 20870),  INT16_C( 26913), -INT16_C( 28720), -INT16_C(  6295), -INT16_C( 19711), -INT16_C( 27996),  INT16_C( 28629) },
      { -INT8_C(  48),  INT8_C(  28), -INT8_C(  54),  INT8_C(  91),  INT8_C(  79), -INT8_C(  54), -INT8_C(  10),  INT8_C(  63) } }
  };
static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec_s32[] = {
    { { -INT32_C(  1850487190),  INT32_C(   807435774),  INT32_C(   528467443), -INT32_C(  1373906768) },
      { -INT32_C(  1555895218), -INT32_C(  2002159770), -INT32_C(  1659108663),  INT32_C(  1719281428) },
      { -INT16_C( 24711), -INT16_C( 27605), -INT16_C(  4064),  INT16_C( 11677) } },
    { {  INT32_C(   691868422), -INT32_C(  1813430623), -INT32_C(   510302452),  INT32_C(   393993334) },
      {  INT32_C(   281248997),  INT32_C(   373757397),  INT32_C(   578177675), -INT32_C(  1587724566) },
      {  INT16_C(  4825),  INT16_C( 15030),  INT16_C( 28079),  INT16_C( 28252) } },
    { { -INT32_C(   739184799), -INT32_C(   298442996), -INT32_C(   438719071),  INT32_C(  1748771821) },
      { -INT32_C(  1209641921), -INT32_C(  1491471134),  INT32_C(  1695003569), -INT32_C(  1691784857) },
      {  INT16_C( 17238), -INT16_C( 17455),  INT16_C( 26616), -INT16_C(  1939) } },
    { { -INT32_C(   247376641), -INT32_C(  1327044214),  INT32_C(  1792239468), -INT32_C(   534079229) },
      {  INT32_C(  2105613095),  INT32_C(  2039404007), -INT32_C(   285142827), -INT32_C(   821312475) },
      { -INT16_C( 21271), -INT16_C( 24514), -INT16_C(  5912), -INT16_C( 12311) } },
    { { -INT32_C(  1645436355), -INT32_C(  2017766971), -INT32_C(  2017941493),  INT32_C(  1077301146) },
      {  INT32_C(   224965715),  INT32_C(  1409439762), -INT32_C(   268844658), -INT32_C(  2005501037) },
      { -INT16_C( 10158), -INT16_C( 18040), -INT16_C( 30704), -INT16_C( 30481) } },
    { {  INT32_C(   848492354), -INT32_C(   701439238),  INT32_C(   870124131),  INT32_C(  1173848403) },
      {  INT32_C(  1544881084), -INT32_C(   642469469), -INT32_C(   554772004), -INT32_C(  1760062397) },
      { -INT16_C(  4705),  INT16_C( 19792),  INT16_C( 24652), -INT16_C( 23337) } },
    { {  INT32_C(   904669787), -INT32_C(   772737521), -INT32_C(   465973947),  INT32_C(  1328495863) },
      { -INT32_C(  1599686724),  INT32_C(  1138514733),  INT32_C(  1034074822),  INT32_C(  1908789852) },
      {  INT16_C( 12782), -INT16_C( 11602), -INT16_C(  2178),  INT16_C( 12036) } },
    { { -INT32_C(   224401834),  INT32_C(  1565020794), -INT32_C(  1228337504),  INT32_C(   292420364) },
      {  INT32_C(  1924325382),  INT32_C(   851171135), -INT32_C(   376501811),  INT32_C(   856058724) },
      {  INT16_C(  3034),  INT16_C( 23205), -INT16_C( 26792), -INT16_C( 20322) } }
  };
static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec_s64[] = {
    { { -INT64_C( 8309300137313876190), -INT64_C( 2120055167042569923) },
      { -INT64_C( 1713608024471425725), -INT64_C( 8537981266181065260) },
      { -INT32_C(   934289434),  INT32_C(  1634219972) } },
    { {  INT64_C( 6642943193227525293),  INT64_C( 2374103345118998483) },
      {  INT64_C( 1108365686850936003),  INT64_C( 8030474717635522743) },
      {  INT32_C(  2035074532),  INT32_C(   694609756) } },
    { {  INT64_C( 1177583856133979864), -INT64_C( 6470827002253639177) },
      { -INT64_C( 1954509707154607962),  INT64_C( 6839655928589097874) },
      { -INT32_C(   342429919), -INT32_C(   537105638) } },
    { {  INT64_C( 5109951925199089911),  INT64_C( 5347955036670443559) },
      {  INT64_C( 7946984878061384042),  INT64_C( 5016268715822709903) },
      { -INT32_C(  1715254818), -INT32_C(   740262115) } },
    { { -INT64_C( 6442760033053250768), -INT64_C(   88794231172123389) },
      {  INT64_C( 1713189599015817908),  INT64_C( 7801060042778592691) },
      {  INT32_C(   257666647), -INT32_C(  1981555920) } },
    { { -INT64_C( 4516876169737122384), -INT64_C( 1763877573654572175) },
      { -INT64_C( 3854453393900553267),  INT64_C( 2808657507726508271) },
      { -INT32_C(   188898461),  INT32_C(  1232599671) } },
    { { -INT64_C( 7993083139582567532), -INT64_C( 8159750613996082896) },
      {  INT64_C( 7701003073780110887), -INT64_C( 2499527131376441464) },
      {  INT32_C(  2077394803), -INT32_C(   696038550) } },
    { { -INT64_C( 7114473241187535639),  INT64_C( 1361802844189616168) },
      {  INT64_C( 6080448044886841829), -INT64_C(  902564201988391023) },
      { -INT32_C(  1854556562),  INT32_C(  1926771707) } }
  };

static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec_u16[] = {
    { { UINT16_C(31537), UINT16_C(33195), UINT16_C(35983), UINT16_C(48613), UINT16_C(19830), UINT16_C(52555), UINT16_C( 2932), UINT16_C(58783) },
      { UINT16_C(62771), UINT16_C(23621), UINT16_C(22599), UINT16_C(13513), UINT16_C(48889), UINT16_C(57800), UINT16_C(62804), UINT16_C(30536) },
      { UINT8_C(184), UINT8_C(226), UINT8_C( 80), UINT8_C(179), UINT8_C(159), UINT8_C( 28), UINT8_C( 97), UINT8_C(  9) } },
    { { UINT16_C(44622), UINT16_C(35027), UINT16_C(40225), UINT16_C(65352), UINT16_C(44805), UINT16_C(46941), UINT16_C(28971), UINT16_C(35378) },
      { UINT16_C(55530), UINT16_C(34091), UINT16_C(22954), UINT16_C(22727), UINT16_C(34695), UINT16_C(45581), UINT16_C(45783), UINT16_C(41657) },
      { UINT8_C(112), UINT8_C(203), UINT8_C(165), UINT8_C( 44), UINT8_C(135), UINT8_C(111), UINT8_C(223), UINT8_C( 35) } },
    { { UINT16_C(19639), UINT16_C(48076), UINT16_C(52505), UINT16_C( 8708), UINT16_C(54307), UINT16_C(64295), UINT16_C(15297), UINT16_C(23392) },
      { UINT16_C(13016), UINT16_C(62154), UINT16_C(35259), UINT16_C(23642), UINT16_C( 5556), UINT16_C(13917), UINT16_C(20616), UINT16_C(45586) },
      { UINT8_C(150), UINT8_C( 14), UINT8_C( 47), UINT8_C( 67), UINT8_C( 77), UINT8_C( 55), UINT8_C(210), UINT8_C(254) } },
    { { UINT16_C(51559), UINT16_C(39467), UINT16_C(30474), UINT16_C(46948), UINT16_C(19575), UINT16_C(48270), UINT16_C(51744), UINT16_C(18666) },
      { UINT16_C(44445), UINT16_C( 5600), UINT16_C(41837), UINT16_C(52397), UINT16_C(38705), UINT16_C(28813), UINT16_C(24820), UINT16_C(33821) },
      { UINT8_C(180), UINT8_C(158), UINT8_C( 26), UINT8_C(139), UINT8_C(218), UINT8_C(207), UINT8_C(214), UINT8_C(230) } },
    { { UINT16_C( 9946), UINT16_C(56786), UINT16_C(13867), UINT16_C(52082), UINT16_C(24895), UINT16_C(43122), UINT16_C(50089), UINT16_C( 7560) },
      { UINT16_C(47345), UINT16_C(59427), UINT16_C(  937), UINT16_C( 6917), UINT16_C(37030), UINT16_C(48600), UINT16_C(53165), UINT16_C(  217) },
      { UINT8_C( 70), UINT8_C( 64), UINT8_C(203), UINT8_C( 95), UINT8_C( 75), UINT8_C(202), UINT8_C(147), UINT8_C(178) } },
    { { UINT16_C(47895), UINT16_C(44475), UINT16_C(26771), UINT16_C(48239), UINT16_C(13244), UINT16_C( 1841), UINT16_C( 3060), UINT16_C(48375) },
      { UINT16_C(46549), UINT16_C(57049), UINT16_C(46693), UINT16_C( 3362), UINT16_C(36840), UINT16_C(15799), UINT16_C(26943), UINT16_C(18864) },
      { UINT8_C(235), UINT8_C(  2), UINT8_C(220), UINT8_C( 61), UINT8_C( 36), UINT8_C( 16), UINT8_C( 25), UINT8_C(250) } },
    { { UINT16_C(33166), UINT16_C( 6090), UINT16_C(47303), UINT16_C(35927), UINT16_C(33838), UINT16_C(19629), UINT16_C(23682), UINT16_C(23907) },
      { UINT16_C(49909), UINT16_C( 6961), UINT16_C(31757), UINT16_C(28956), UINT16_C(16552), UINT16_C(15228), UINT16_C(25781), UINT16_C(14861) },
      { UINT8_C( 29), UINT8_C(152), UINT8_C(159), UINT8_C(130), UINT8_C(251), UINT8_C(201), UINT8_C( 51), UINT8_C(111) } },
    { { UINT16_C(23893), UINT16_C( 3729), UINT16_C( 5223), UINT16_C(56758), UINT16_C(35016), UINT16_C(64887), UINT16_C(39938), UINT16_C(46922) },
      { UINT16_C(19010), UINT16_C(53456), UINT16_C(40641), UINT16_C(51608), UINT16_C(45423), UINT16_C( 4561), UINT16_C(39890), UINT16_C(40942) },
      { UINT8_C(  3), UINT8_C( 12), UINT8_C(251), UINT8_C(204), UINT8_C(148), UINT8_C(150), UINT8_C( 18), UINT8_C(111) } }
  };

static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec_u32[] = {
    { { UINT32_C(4190033919), UINT32_C(1744321202), UINT32_C(3736257165), UINT32_C(3014913437) },
      { UINT32_C( 398266754), UINT32_C(1122850928), UINT32_C(3240709731), UINT32_C(1035264997) },
      { UINT16_C(12442), UINT16_C(61565), UINT16_C(16114), UINT16_C(43104) } },
    { { UINT32_C(2024219938), UINT32_C(2532957755), UINT32_C(2966014432), UINT32_C(   4854876) },
      { UINT32_C(3031325551), UINT32_C( 294464975), UINT32_C(1153362455), UINT32_C(2321921242) },
      { UINT16_C(51254), UINT16_C(22003), UINT16_C(49379), UINT16_C(32400) } },
    { { UINT32_C(4063461955), UINT32_C(2591947519), UINT32_C(3942738256), UINT32_C(2897394847) },
      { UINT32_C(2338812053), UINT32_C( 566259394), UINT32_C(1235477372), UINT32_C(3038252023) },
      { UINT16_C(16180), UINT16_C( 8928), UINT16_C(27933), UINT16_C(32266) } },
    { { UINT32_C( 604517562), UINT32_C( 415944889), UINT32_C(1284411115), UINT32_C(2603526974) },
      { UINT32_C(3130955266), UINT32_C(2627258028), UINT32_C(4045874852), UINT32_C(1580544603) },
      { UINT16_C(33358), UINT16_C(35501), UINT16_C(36819), UINT16_C(  635) } },
    { { UINT32_C(2864821708), UINT32_C(1453440798), UINT32_C( 363851535), UINT32_C(2188438986) },
      { UINT32_C(2846048652), UINT32_C(3349648563), UINT32_C(2875436017), UINT32_C( 265807160) },
      { UINT16_C(15841), UINT16_C( 9818), UINT16_C(46186), UINT16_C(62057) } },
    { { UINT32_C(1167650562), UINT32_C(1967314026), UINT32_C(1778338958), UINT32_C(3039135995) },
      { UINT32_C(1840978738), UINT32_C( 835480319), UINT32_C(1304933355), UINT32_C(1818752355) },
      { UINT16_C(37935), UINT16_C(10780), UINT16_C(38069), UINT16_C( 8675) } },
    { { UINT32_C(1522758799), UINT32_C( 708237663), UINT32_C(  82828961), UINT32_C(4237512016) },
      { UINT32_C(1860048859), UINT32_C( 859370624), UINT32_C( 185587644), UINT32_C(2605279391) },
      { UINT16_C( 7768), UINT16_C(58402), UINT16_C(18143), UINT16_C(50904) } },
    { { UINT32_C(3950060082), UINT32_C(  18429340), UINT32_C(1445340920), UINT32_C( 979618665) },
      { UINT32_C( 291748993), UINT32_C(1081482408), UINT32_C(3821777457), UINT32_C(1495838412) },
      { UINT16_C(48793), UINT16_C(54903), UINT16_C(10209), UINT16_C( 7538) } }
  };

static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec_u64[] = {
    { { UINT64_C( 1552025503746466293), UINT64_C( 9758012425155071717) },
      { UINT64_C( 8940830851167705729), UINT64_C(15367813426609698727) },
      { UINT32_C(1371115795), UINT32_C( 126921017) } },
    { { UINT64_C(15425511801045299131), UINT64_C( 2668781658281004397) },
      { UINT64_C(12122432817139075498), UINT64_C( 2221705505121733441) },
      { UINT32_C(1678710051), UINT32_C(1546449716) } },
    { { UINT64_C( 4583654534523196531), UINT64_C( 7524381970885961929) },
      { UINT64_C( 5284251603917601590), UINT64_C(16303584298985706853) },
      { UINT32_C(2427342345), UINT32_C(1044448517) } },
    { { UINT64_C(10145278222742768742), UINT64_C( 7557569178841081743) },
      { UINT64_C(12002371849911232976), UINT64_C(13326134382080063551) },
      { UINT32_C(2344513909), UINT32_C(2375600257) } },
    { { UINT64_C( 7657856551790097907), UINT64_C( 3239909736982410392) },
      { UINT64_C(17930196679403975765), UINT64_C( 3733387305402475234) },
      { UINT32_C(4252856871), UINT32_C(1535065132) } },
    { { UINT64_C( 1865109292892866998), UINT64_C(10666106303195351650) },
      { UINT64_C(17405760262541507816), UINT64_C( 9431068424702399799) },
      { UINT32_C( 217346242), UINT32_C(  88323585) } },
    { { UINT64_C(  442310546234455531), UINT64_C( 4362362751774226035) },
      { UINT64_C( 8163454742249884811), UINT64_C( 6012774413815623635) },
      { UINT32_C( 613081987), UINT32_C(1041550856) } },
    { { UINT64_C(15744050947108988032), UINT64_C( 2040212694681598218) },
      { UINT64_C(  441426606847429982), UINT64_C( 4371038746585661036) },
      { UINT32_C(1013121395), UINT32_C(1100185026) } }
  };
TEST(sub, vrsubhn_high)
{
    // vsubhn_type: sub, half narrow
    // r = vsubhn_type(a, b), a和b是宽类型，r是(a-b)右移n/2位后的结果（高n/2位）
    
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    // EXPECT_TRUE(almostEqual(expected, actual));
}

void f1(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s16) / sizeof(test_vec_s16[0])) ; i++) {
        int16x8_t a = vld1q_s16(test_vec_s16[i].a);
        // printf("test:\n");
        // for (int i = 0; i < 8; i++)
        // {
        //     printf("%hd, ", a[i]);
        // }
        // printf("\ntest end\n");
        int16x8_t b = vld1q_s16(test_vec_s16[i].b);
        int8x8_t  r = vld1_s8(test_vec_s16[i].r);
        int8x16_t rst = vrsubhn_high_s16(r, a, b);
        printf("{ ");
        for(int j = 0;j < 16;j ++){
            test_codegen_i8(rst[j]);
            if(j != 15)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int32x4_t b = vld1q_s32(test_vec_s32[i].b);
        int16x4_t  r = vld1_s16(test_vec_s32[i].r);
        int16x8_t rst = vrsubhn_high_s32(r, a, b);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_i16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f3(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        int64x2_t b = vld1q_s64(test_vec_s64[i].b);
        int32x2_t  r = vld1_s32(test_vec_s64[i].r);
        int32x4_t rst = vrsubhn_high_s64(r, a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_i32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f4(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint16x8_t b = vld1q_u16(test_vec_u16[i].b);
        uint8x8_t  r = vld1_u8(test_vec_u16[i].r);
        uint8x16_t rst = vrsubhn_high_u16(r, a, b);

        printf("{ ");
        for(int j = 0;j < 16;j ++){
            test_codegen_u8(rst[j]);
            if(j != 15)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f5(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint32x4_t b = vld1q_u32(test_vec_u32[i].b);
        uint16x4_t  r = vld1_u16(test_vec_u32[i].r);
        uint16x8_t rst = vrsubhn_high_u32(r, a, b);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_u16(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f6(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u64) / sizeof(test_vec_u64[0])) ; i++) {
        uint64x2_t a = vld1q_u64(test_vec_u64[i].a);
        uint64x2_t b = vld1q_u64(test_vec_u64[i].b);
        uint32x2_t  r = vld1_u32(test_vec_u64[i].r);
        uint32x4_t rst = vrsubhn_high_u64(r, a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}