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
    { { -INT16_C( 25091),  INT16_C(  4094), -INT16_C(  3999),  INT16_C( 22729),  INT16_C(  9746), -INT16_C(  7336),  INT16_C( 16803),  INT16_C( 29761) },
      { -INT16_C( 30435), -INT16_C( 25676), -INT16_C(  5893),  INT16_C(  7506),  INT16_C(  1743),  INT16_C(  5650), -INT16_C( 23748), -INT16_C( 30577) },
      {  INT8_C( 125),  INT8_C(  73),  INT8_C(  50),  INT8_C(  42),  INT8_C(  56), -INT8_C(  56),  INT8_C(  67), -INT8_C( 111) } },
    { {  INT16_C( 19861),  INT16_C( 26454),  INT16_C( 32027), -INT16_C( 26345), -INT16_C(   861), -INT16_C( 28134), -INT16_C( 22930), -INT16_C( 24884) },
      {  INT16_C( 30899),  INT16_C( 22168),  INT16_C( 16349), -INT16_C(  4187), -INT16_C( 31337),  INT16_C( 25811), -INT16_C( 28754), -INT16_C( 25635) },
      {  INT8_C(  90),  INT8_C( 103),  INT8_C(  18),  INT8_C(   6), -INT8_C( 118),  INT8_C(  91),  INT8_C(  44),  INT8_C( 122) } },
    { {  INT16_C( 21464), -INT16_C(  8527),  INT16_C(  5888),  INT16_C( 24648),  INT16_C(  8788),  INT16_C( 22161), -INT16_C( 20503), -INT16_C(  2581) },
      { -INT16_C(  4732), -INT16_C(  2779),  INT16_C( 26511),  INT16_C( 11438), -INT16_C(  8867), -INT16_C( 24627), -INT16_C(  2750),  INT16_C( 23524) },
      { -INT8_C(  86),  INT8_C(  44), -INT8_C(   5),  INT8_C( 125), -INT8_C(  68), -INT8_C(  56),  INT8_C(  52),  INT8_C( 112) } },
    { {  INT16_C( 15659),  INT16_C(  1870),  INT16_C( 10371), -INT16_C( 16489),  INT16_C( 17098),  INT16_C( 29093), -INT16_C( 23521),  INT16_C( 28428) },
      { -INT16_C( 11996),  INT16_C( 30424), -INT16_C(  5667),  INT16_C( 30737),  INT16_C( 27771),  INT16_C( 19342),  INT16_C(  3446), -INT16_C( 16700) },
      { -INT8_C(  67), -INT8_C(  55),  INT8_C( 106),  INT8_C(  32), -INT8_C(  58), -INT8_C(  36),  INT8_C(  59), -INT8_C(  76) } },
    { {  INT16_C( 28742), -INT16_C( 30592), -INT16_C( 19075), -INT16_C( 24734), -INT16_C(  3962), -INT16_C( 19769),  INT16_C(  1637),  INT16_C( 23174) },
      { -INT16_C( 13403),  INT16_C( 15116),  INT16_C( 28338),  INT16_C( 14159), -INT16_C( 10526),  INT16_C(  5764),  INT16_C(  9329),  INT16_C( 22738) },
      {  INT8_C(  50), -INT8_C(  94),  INT8_C(   9), -INT8_C(  61),  INT8_C(  11),  INT8_C(  24),  INT8_C(   6), -INT8_C(  92) } },
    { {  INT16_C( 16493), -INT16_C( 10068), -INT16_C(  1161),  INT16_C( 14766),  INT16_C( 26882), -INT16_C( 26090),  INT16_C(  6283), -INT16_C(  5987) },
      { -INT16_C( 11767),  INT16_C(  8428), -INT16_C( 20598),  INT16_C( 11740),  INT16_C( 19497),  INT16_C( 16942),  INT16_C( 17364), -INT16_C( 18931) },
      { -INT8_C(  97), -INT8_C(  19),  INT8_C(  73),  INT8_C(  79),  INT8_C( 104),  INT8_C(   6),  INT8_C(  36),  INT8_C(  89) } },
    { {  INT16_C( 21360),  INT16_C( 19270),  INT16_C( 18838),  INT16_C(  6215), -INT16_C( 10110),  INT16_C( 12899), -INT16_C( 19710), -INT16_C( 28302) },
      {  INT16_C( 15406),  INT16_C( 31218), -INT16_C( 26638), -INT16_C(  3037),  INT16_C(  5509), -INT16_C( 10425), -INT16_C( 25230),  INT16_C( 26435) },
      {  INT8_C(  88),  INT8_C(  24),  INT8_C(  33),  INT8_C(   3), -INT8_C(  54), -INT8_C(  68),  INT8_C(   4),  INT8_C( 104) } },
    { { -INT16_C(    66), -INT16_C(  1591),  INT16_C(  6240), -INT16_C( 26278), -INT16_C( 23375), -INT16_C(  4134),  INT16_C( 18420),  INT16_C(  2145) },
      { -INT16_C( 25874),  INT16_C(  3180),  INT16_C(  9425), -INT16_C(  9532),  INT16_C( 21812), -INT16_C( 29937),  INT16_C(  7270), -INT16_C(  3581) },
      { -INT8_C( 100), -INT8_C(  89), -INT8_C(  40), -INT8_C(  33),  INT8_C(  98), -INT8_C(  91),  INT8_C(  35), -INT8_C(  12) } }
  };
static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec_s32[] = {
    { { -INT32_C(    43045480), -INT32_C(  1037938878), -INT32_C(   489361961),  INT32_C(  1313707502) },
      { -INT32_C(    95272939),  INT32_C(  1665232598),  INT32_C(    47761064), -INT32_C(  1003277403) },
      {  INT16_C(    66), -INT16_C( 30039),  INT16_C( 22917), -INT16_C( 18725) } },
    { {  INT32_C(   606199343), -INT32_C(   485609593), -INT32_C(   151307478),  INT32_C(   517898652) },
      {  INT32_C(   945174376),  INT32_C(  2128860238), -INT32_C(   915547508), -INT32_C(   588336368) },
      {  INT16_C( 26529), -INT16_C(  3914),  INT16_C(  9933), -INT16_C( 25522) } },
    { { -INT32_C(   237150653),  INT32_C(  1450531120),  INT32_C(   165087900), -INT32_C(   913045333) },
      { -INT32_C(    84012068),  INT32_C(   729953853),  INT32_C(   938179926), -INT32_C(  1156951916) },
      {  INT16_C(  1881),  INT16_C( 26249), -INT16_C( 23827),  INT16_C( 12143) } },
    { { -INT32_C(  1366045306),  INT32_C(  1539499482),  INT32_C(   594915873),  INT32_C(   978926301) },
      {  INT32_C(  1011015611),  INT32_C(   579194994),  INT32_C(   406742807), -INT32_C(   648275471) },
      { -INT16_C(  8398),  INT16_C(  4134),  INT16_C( 19058), -INT16_C( 10467) } },
    { { -INT32_C(   751339808), -INT32_C(   626753639),  INT32_C(   245489483), -INT32_C(  1394423320) },
      {  INT32_C(  1373966681), -INT32_C(  1320813048), -INT32_C(   968115270), -INT32_C(  1415706328) },
      { -INT16_C(  5839), -INT16_C(  8340),  INT16_C(  8023), -INT16_C( 17443) } },
    { {  INT32_C(   142816337), -INT32_C(  1867183227),  INT32_C(   486639799),  INT32_C(  1577549967) },
      {  INT32_C(   294406284), -INT32_C(   274917006),  INT32_C(   460417486),  INT32_C(    43546787) },
      { -INT16_C( 14160),  INT16_C( 21298), -INT16_C( 17134), -INT16_C( 16481) } },
    { { -INT32_C(  1935029491), -INT32_C(   324654503), -INT32_C(   587323984),  INT32_C(  1088929329) },
      {  INT32_C(   508836626), -INT32_C(   329375980),  INT32_C(  1559856040),  INT32_C(  1021251504) },
      { -INT16_C(  6663), -INT16_C(  5251),  INT16_C( 21656), -INT16_C(  4189) } },
    { { -INT32_C(  1158416111), -INT32_C(  1563115693),  INT32_C(     4560387),  INT32_C(  1786694064) },
      {  INT32_C(  1499340188), -INT32_C(  2115246331),  INT32_C(   144407913), -INT32_C(  1638691389) },
      { -INT16_C( 16451), -INT16_C(  7246), -INT16_C( 29314),  INT16_C( 23390) } }
  };
static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec_s64[] = {
    { { -INT64_C( 4546316388246114472), -INT64_C( 2808401879475164966) },
      { -INT64_C(  994155906384569059), -INT64_C( 3155768039297051344) },
      { -INT32_C(  1568093060),  INT32_C(   603930142) } },
    { { -INT64_C( 4552190517215059106), -INT64_C( 4448113431959173328) },
      {  INT64_C( 8274744101089282713),  INT64_C( 6228617685183450776) },
      {  INT32_C(   289882777),  INT32_C(  1072591999) } },
    { { -INT64_C( 1920618994591645288),  INT64_C( 8835811607606455583) },
      {  INT64_C( 5191673011057247126),  INT64_C( 5513065108306903097) },
      { -INT32_C(  1484676429),  INT32_C(  1282224733) } },
    { { -INT64_C( 1518461391101126106), -INT64_C( 5362191478787412186) },
      {  INT64_C( 2800301385976376300),  INT64_C( 2379047572631461832) },
      { -INT32_C(   515783016),  INT32_C(  1529282952) } },
    { { -INT64_C( 4638718260238230071), -INT64_C( 5330889087084186071) },
      { -INT64_C( 1696125887023374959), -INT64_C( 2532607698046234326) },
      { -INT32_C(  1870271278), -INT32_C(  1872948345) } },
    { { -INT64_C( 1561383586596552205), -INT64_C( 7473558840256922690) },
      { -INT64_C( 3328263790340435553), -INT64_C(  685599608594571153) },
      {  INT32_C(   208071841),  INT32_C(   319333421) } },
    { { -INT64_C( 4718872907742961542), -INT64_C( 3305895917415128813) },
      {  INT64_C(  213715384442350253),  INT64_C( 5033932948310892708) },
      {  INT32_C(  1346080759), -INT32_C(  1777604981) } },
    { { -INT64_C( 8769809969929605315), -INT64_C( 6418112659485836160) },
      { -INT64_C( 5288164611251395766),  INT64_C( 3382238178593467371) },
      { -INT32_C(  2001351498), -INT32_C(  2041476495) } }
  };

static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec_u16[] = {
    { { UINT16_C(37830), UINT16_C(10311), UINT16_C(54924), UINT16_C(20859), UINT16_C(41866), UINT16_C(20325), UINT16_C(55318), UINT16_C( 6076) },
      { UINT16_C( 3872), UINT16_C(10376), UINT16_C(16445), UINT16_C(33228), UINT16_C(46146), UINT16_C(11234), UINT16_C(20699), UINT16_C(14018) },
      { UINT8_C( 82), UINT8_C( 72), UINT8_C(168), UINT8_C(146), UINT8_C(106), UINT8_C(196), UINT8_C(137), UINT8_C(144) } },
    { { UINT16_C(49604), UINT16_C(55640), UINT16_C( 5636), UINT16_C(63471), UINT16_C( 5617), UINT16_C( 2399), UINT16_C( 3035), UINT16_C(37906) },
      { UINT16_C( 8975), UINT16_C(16223), UINT16_C(16702), UINT16_C(42966), UINT16_C(23275), UINT16_C(49405), UINT16_C( 7974), UINT16_C(43690) },
      { UINT8_C(138), UINT8_C(101), UINT8_C( 11), UINT8_C(129), UINT8_C(220), UINT8_C( 94), UINT8_C(186), UINT8_C( 30) } },
    { { UINT16_C(59093), UINT16_C(64089), UINT16_C( 4917), UINT16_C(38758), UINT16_C( 7941), UINT16_C(44171), UINT16_C(61045), UINT16_C(28807) },
      { UINT16_C(  602), UINT16_C(42964), UINT16_C( 6854), UINT16_C(16619), UINT16_C( 2149), UINT16_C(  845), UINT16_C(58615), UINT16_C(60944) },
      { UINT8_C(229), UINT8_C(203), UINT8_C(105), UINT8_C( 25), UINT8_C(203), UINT8_C( 38), UINT8_C(245), UINT8_C(  3) } },
    { { UINT16_C(18433), UINT16_C(58289), UINT16_C( 6433), UINT16_C(37795), UINT16_C(15209), UINT16_C(56260), UINT16_C(64701), UINT16_C(59566) },
      { UINT16_C(  669), UINT16_C(17485), UINT16_C(50282), UINT16_C(48608), UINT16_C(63328), UINT16_C(41323), UINT16_C(49625), UINT16_C(46026) },
      { UINT8_C( 35), UINT8_C( 35), UINT8_C(182), UINT8_C(218), UINT8_C( 85), UINT8_C(228), UINT8_C(226), UINT8_C( 83) } },
    { { UINT16_C(54253), UINT16_C(20715), UINT16_C( 3915), UINT16_C(52346), UINT16_C(23803), UINT16_C(52952), UINT16_C(44847), UINT16_C(14000) },
      { UINT16_C( 5682), UINT16_C(11290), UINT16_C(30527), UINT16_C( 2337), UINT16_C(27411), UINT16_C( 4567), UINT16_C(64057), UINT16_C( 7166) },
      { UINT8_C(203), UINT8_C(120), UINT8_C( 96), UINT8_C( 23), UINT8_C(233), UINT8_C(141), UINT8_C(216), UINT8_C( 76) } },
    { { UINT16_C(38548), UINT16_C(21125), UINT16_C(39748), UINT16_C(46901), UINT16_C(56442), UINT16_C(61960), UINT16_C(25448), UINT16_C( 1986) },
      { UINT16_C(24642), UINT16_C(34905), UINT16_C(50862), UINT16_C(21193), UINT16_C(51197), UINT16_C( 7081), UINT16_C(36268), UINT16_C(37925) },
      { UINT8_C(138), UINT8_C(127), UINT8_C(245), UINT8_C( 32), UINT8_C(216), UINT8_C(109), UINT8_C(225), UINT8_C(171) } },
    { { UINT16_C(37648), UINT16_C(  654), UINT16_C(38446), UINT16_C(28244), UINT16_C( 3894), UINT16_C(49217), UINT16_C(38649), UINT16_C(16704) },
      { UINT16_C(23450), UINT16_C(57138), UINT16_C(62892), UINT16_C(16997), UINT16_C(64214), UINT16_C(43778), UINT16_C(44397), UINT16_C(61571) },
      { UINT8_C( 11), UINT8_C(168), UINT8_C(200), UINT8_C(131), UINT8_C(191), UINT8_C(130), UINT8_C(178), UINT8_C(223) } },
    { { UINT16_C(42700), UINT16_C(48140), UINT16_C(54372), UINT16_C(61349), UINT16_C(55003), UINT16_C(16581), UINT16_C(25193), UINT16_C(   34) },
      { UINT16_C(54284), UINT16_C( 1271), UINT16_C(12033), UINT16_C(11221), UINT16_C(14662), UINT16_C(62856), UINT16_C(28295), UINT16_C(62789) },
      { UINT8_C(128), UINT8_C(194), UINT8_C( 99), UINT8_C(251), UINT8_C(231), UINT8_C( 44), UINT8_C(145), UINT8_C(251) } }
  };

static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec_u32[] = {
    { { UINT32_C( 788264481), UINT32_C( 574102579), UINT32_C(1455983137), UINT32_C( 789955375) },
      { UINT32_C(1749984489), UINT32_C(1666637075), UINT32_C(1993390259), UINT32_C(2131672268) },
      { UINT16_C(40441), UINT16_C(27317), UINT16_C(65422), UINT16_C(17586) } },
    { { UINT32_C(1799626291), UINT32_C(1436410715), UINT32_C(3208320491), UINT32_C( 392495606) },
      { UINT32_C(2708989679), UINT32_C(3987293530), UINT32_C(1234494246), UINT32_C(3936251287) },
      { UINT16_C(57419), UINT16_C( 8270), UINT16_C(24788), UINT16_C(56694) } },
    { { UINT32_C(4010480282), UINT32_C(1384261300), UINT32_C(1757938736), UINT32_C(3935130994) },
      { UINT32_C(1835737764), UINT32_C( 484391279), UINT32_C(3977592359), UINT32_C(1257181690) },
      { UINT16_C( 3362), UINT16_C(14342), UINT16_C( 9121), UINT16_C(52126) } },
    { { UINT32_C( 725248806), UINT32_C( 814970685), UINT32_C(2243364016), UINT32_C(  67868570) },
      { UINT32_C(1531155967), UINT32_C(3274867305), UINT32_C(1744628754), UINT32_C(3353723854) },
      { UINT16_C(27521), UINT16_C(48637), UINT16_C(25295), UINT16_C(26973) } },
    { { UINT32_C( 219517643), UINT32_C(2386102636), UINT32_C(2268854088), UINT32_C(1860083222) },
      { UINT32_C( 339058400), UINT32_C(1041316585), UINT32_C(1689293105), UINT32_C( 241771982) },
      { UINT16_C(17092), UINT16_C( 1720), UINT16_C(19818), UINT16_C(  990) } },
    { { UINT32_C(2638807935), UINT32_C(3482739582), UINT32_C(3714884467), UINT32_C(4123233575) },
      { UINT32_C(3541826478), UINT32_C(1160270869), UINT32_C(3151954874), UINT32_C(2862369713) },
      { UINT16_C(44012), UINT16_C(23259), UINT16_C(35783), UINT16_C( 9887) } },
    { { UINT32_C(2814418598), UINT32_C(2614625064), UINT32_C( 786474561), UINT32_C(3239459677) },
      { UINT32_C(2068401445), UINT32_C(1679689054), UINT32_C(2243298662), UINT32_C(3446619368) },
      { UINT16_C(57551), UINT16_C(55985), UINT16_C(37600), UINT16_C(59837) } },
    { { UINT32_C(   3520068), UINT32_C(2613774308), UINT32_C(1471164892), UINT32_C(1273659634) },
      { UINT32_C(1898715422), UINT32_C(2554901707), UINT32_C(2702047558), UINT32_C(3267906934) },
      { UINT16_C(52077), UINT16_C(16790), UINT16_C(62478), UINT16_C(13846) } }
  };

static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec_u64[] = {
  { { UINT64_C( 5709079685660958744), UINT64_C( 3372067448430113378) },
      { UINT64_C( 5443676795552351207), UINT64_C( 1806084258100496917) },
      { UINT32_C(3991748988), UINT32_C(3570437168) } },
    { { UINT64_C( 7822913358318675299), UINT64_C( 1165512440976077983) },
      { UINT64_C(14787168702917029494), UINT64_C( 5966327681261893916) },
      { UINT32_C(1495737851), UINT32_C(3250197711) } },
    { { UINT64_C( 2070253103106893546), UINT64_C(13652576930398656252) },
      { UINT64_C(17474659759657877377), UINT64_C(10200362234298994292) },
      { UINT32_C(3776998239), UINT32_C( 461996987) } },
    { { UINT64_C( 1536619167436722049), UINT64_C( 3049799826062156721) },
      { UINT64_C( 8865946101272950349), UINT64_C( 8536942127930955828) },
      { UINT32_C(2227349658), UINT32_C(2615950675) } },
    { { UINT64_C( 6736587465545424948), UINT64_C(16607537552261559810) },
      { UINT64_C( 8240795966564766660), UINT64_C(10528383898149371098) },
      { UINT32_C(  12299288), UINT32_C(2046425943) } },
    { { UINT64_C( 3462397775737404878), UINT64_C( 5568155006095450643) },
      { UINT64_C(10776317654908862488), UINT64_C(10757190746834338043) },
      { UINT32_C(1941462133), UINT32_C( 627896584) } },
    { { UINT64_C( 6836008491821741913), UINT64_C( 8633396822004257717) },
      { UINT64_C(10255524856883047437), UINT64_C( 6220223664024638216) },
      { UINT32_C(1801896579), UINT32_C( 834508263) } },
    { { UINT64_C( 2264381484422187748), UINT64_C(11904017984182247962) },
      { UINT64_C( 8727899594093322667), UINT64_C(11870510519812586426) },
      { UINT32_C(4215341804), UINT32_C(1794970463) } }
  };
int main(){
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
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
        int8x16_t rst = vsubhn_high_s16(r, a, b);
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
        int16x8_t rst = vsubhn_high_s32(r, a, b);

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
        int32x4_t rst = vsubhn_high_s64(r, a, b);

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
        uint8x16_t rst = vsubhn_high_u16(r, a, b);

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
        uint16x8_t rst = vsubhn_high_u32(r, a, b);

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
        uint32x4_t rst = vsubhn_high_u64(r, a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u32(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

