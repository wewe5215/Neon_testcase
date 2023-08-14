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
    { { -INT16_C(  7291),  INT16_C(  9638), -INT16_C( 29468), -INT16_C( 26247),  INT16_C(  1239), -INT16_C( 12968),  INT16_C( 11978), -INT16_C( 27963) },
      {  INT16_C( 10464),  INT16_C(  4090), -INT16_C(  7432), -INT16_C( 17159), -INT16_C( 29853), -INT16_C( 17484),  INT16_C( 28857), -INT16_C( 16842) } },
    { {  INT16_C( 19792), -INT16_C(  2327),  INT16_C( 32336), -INT16_C( 14244),  INT16_C( 14781),  INT16_C( 18679),  INT16_C(  3770),  INT16_C( 15040) },
      { -INT16_C(  4676), -INT16_C( 28408), -INT16_C( 25598), -INT16_C( 28651), -INT16_C(  4842),  INT16_C(   342),  INT16_C( 18788),  INT16_C( 31280) } },
    { { -INT16_C( 15241), -INT16_C(  4112),  INT16_C(  2371), -INT16_C(  2785),  INT16_C(  5510),  INT16_C( 10457), -INT16_C( 19774), -INT16_C( 11050) },
      {  INT16_C( 27130),  INT16_C(  8466),  INT16_C( 29049), -INT16_C(  1453),  INT16_C(   420),  INT16_C(  8178), -INT16_C(  2153),  INT16_C( 17922) } },
    { { -INT16_C(   501),  INT16_C( 14031),  INT16_C( 27762), -INT16_C(  3890), -INT16_C( 19201), -INT16_C( 16417), -INT16_C(  4020), -INT16_C( 12783) },
      { -INT16_C(  7856), -INT16_C( 25122),  INT16_C( 17358), -INT16_C( 14490),  INT16_C( 13704),  INT16_C( 31955), -INT16_C(  9330),  INT16_C( 27395) } },
    { {  INT16_C( 22607), -INT16_C( 10238),  INT16_C( 29071),  INT16_C( 29731),  INT16_C( 22504),  INT16_C( 29424), -INT16_C(  7017), -INT16_C( 21344) },
      {  INT16_C( 14041), -INT16_C( 27389), -INT16_C(  6443),  INT16_C( 29644), -INT16_C(   832),  INT16_C( 16912), -INT16_C(  8417), -INT16_C(  6361) } },
    { { -INT16_C( 32033),  INT16_C(  8447), -INT16_C(  1074),  INT16_C( 27260), -INT16_C(  9511), -INT16_C( 10419),  INT16_C( 15872),  INT16_C(  1163) },
      {  INT16_C(  5050),  INT16_C( 11261),  INT16_C( 11462), -INT16_C(  7357), -INT16_C( 19142), -INT16_C(  1178),  INT16_C( 19071), -INT16_C(  5576) } },
    { {  INT16_C( 11989), -INT16_C(   815), -INT16_C( 29075),  INT16_C(  9427),  INT16_C(  6957), -INT16_C( 11037), -INT16_C( 29115), -INT16_C( 32663) },
      {  INT16_C(  7372), -INT16_C(  4279), -INT16_C(  2748),  INT16_C(  9532), -INT16_C( 26059),  INT16_C( 12557), -INT16_C( 30201),  INT16_C( 21513) } },
    { { -INT16_C( 16913),  INT16_C( 22697), -INT16_C(  6600), -INT16_C( 25423),  INT16_C( 28387), -INT16_C( 16983), -INT16_C( 27441), -INT16_C( 10725) },
      {  INT16_C(  6971), -INT16_C( 16270),  INT16_C( 14439),  INT16_C( 11864), -INT16_C( 19799),  INT16_C(  2444),  INT16_C(   765),  INT16_C( 13491) } }
  };

static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec_s32[] = {
    { {  INT32_C(  2088169653), -INT32_C(  1289192175),  INT32_C(  1911424902), -INT32_C(   847541263) },
      { -INT32_C(  1523502795), -INT32_C(  1714021956), -INT32_C(   476923219),  INT32_C(  1170332761) } },
    { {  INT32_C(  1752928672),  INT32_C(  1808146549),  INT32_C(  2058643472),  INT32_C(   857111095) },
      { -INT32_C(  1317404537),  INT32_C(  1662053967), -INT32_C(   104261668),  INT32_C(  1802555529) } },
    { {  INT32_C(   921118013),  INT32_C(   713848575),  INT32_C(   637916120), -INT32_C(   471694684) },
      { -INT32_C(   577119670), -INT32_C(  1444195152), -INT32_C(    89013827),  INT32_C(   903673912) } },
    { {  INT32_C(  2019989848), -INT32_C(   152988426), -INT32_C(  1370901650), -INT32_C(  1074517506) },
      { -INT32_C(   414911868),  INT32_C(  1733442553), -INT32_C(  1452461274),  INT32_C(  1480563990) } },
    { { -INT32_C(  1883377890), -INT32_C(  1282373688),  INT32_C(  1234701704), -INT32_C(  1405899504) },
      {  INT32_C(   816940498),  INT32_C(   950596308),  INT32_C(  2141476516),  INT32_C(   706544284) } },
    { {  INT32_C(   324857156),  INT32_C(  1605690780),  INT32_C(  1394208229), -INT32_C(  1810674447) },
      { -INT32_C(  1699869428),  INT32_C(   272709249),  INT32_C(  1095595747),  INT32_C(   662975954) } },
    { {  INT32_C(   703843372),  INT32_C(  1404458957),  INT32_C(  1749931315),  INT32_C(  1665570123) },
      {  INT32_C(  1756851433), -INT32_C(    53066789), -INT32_C(  1500633586),  INT32_C(  1799019541) } },
    { { -INT32_C(   418586353), -INT32_C(  2126631816), -INT32_C(  2140132617),  INT32_C(    58046882) },
      {  INT32_C(   403250089), -INT32_C(   520233376), -INT32_C(   242600132),  INT32_C(   788071134) } }
  };

  static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec_s64[] = {
    { { -INT64_C( 5896086038255676386),  INT64_C( 6698774137223291249) },
      {  INT64_C( 3863354239581181882),  INT64_C( 5089323252144971728) } },
    { { -INT64_C( 5220589478318717525),  INT64_C( 5945096944345067395) },
      { -INT64_C( 4078896564509716388), -INT64_C( 6598671661861736733) } },
    { { -INT64_C( 4139859652416176563), -INT64_C( 4474661492786595946) },
      {  INT64_C( 8304626525242742599), -INT64_C( 3445593515556227416) } },
    { { -INT64_C( 7388753906778791415),  INT64_C( 8990108376245188482) },
      { -INT64_C( 2031348400342627243),  INT64_C( 7674283054084487893) } },
    { { -INT64_C( 5000011665988461963),  INT64_C( 5637240725164930416) },
      {  INT64_C( 5899399823313308451), -INT64_C( 6558892338496954365) } },
    { { -INT64_C( 4657119603271400992), -INT64_C(  816338651829882682) },
      {  INT64_C( 4671678757377448889), -INT64_C( 4292789731161875942) } },
    { { -INT64_C( 8641905208291601035),  INT64_C( 1900572111068744200) },
      {  INT64_C( 4266339929742826546), -INT64_C( 6913496463864457035) } },
    { {  INT64_C( 9005891503995724647),  INT64_C( 6867661247313377983) },
      { -INT64_C( 7635353211472972706),  INT64_C( 2070946294951375750) } }
  };

static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec_u16[] = {
    { { UINT16_C(63247), UINT16_C(62354), UINT16_C(20632), UINT16_C(51531), UINT16_C(31072), UINT16_C(53933), UINT16_C(13441), UINT16_C(19909) },
      { UINT16_C(49005), UINT16_C(50068), UINT16_C(20678), UINT16_C(10591), UINT16_C(40382), UINT16_C( 1424), UINT16_C(16124), UINT16_C(43562) } },
    { { UINT16_C(18458), UINT16_C(48125), UINT16_C(56402), UINT16_C(41226), UINT16_C(11572), UINT16_C(42649), UINT16_C(30010), UINT16_C(23334) },
      { UINT16_C(31631), UINT16_C( 1066), UINT16_C(57818), UINT16_C( 3771), UINT16_C(52853), UINT16_C(46287), UINT16_C(59798), UINT16_C(50196) } },
    { { UINT16_C( 9896), UINT16_C(28701), UINT16_C(61349), UINT16_C(30487), UINT16_C( 6712), UINT16_C(53450), UINT16_C(46730), UINT16_C(59549) },
      { UINT16_C(63135), UINT16_C(23953), UINT16_C(53234), UINT16_C(24978), UINT16_C(12554), UINT16_C(59792), UINT16_C( 1327), UINT16_C(28031) } },
    { { UINT16_C(26998), UINT16_C(62545), UINT16_C(50547), UINT16_C(15895), UINT16_C(53001), UINT16_C(53297), UINT16_C(24175), UINT16_C(15059) },
      { UINT16_C(48839), UINT16_C(52448), UINT16_C(41205), UINT16_C(64696), UINT16_C(54927), UINT16_C(41267), UINT16_C(10718), UINT16_C(45287) } },
    { { UINT16_C(57349), UINT16_C(56684), UINT16_C(29485), UINT16_C(42863), UINT16_C(22472), UINT16_C( 2767), UINT16_C(27464), UINT16_C(32675) },
      { UINT16_C(19750), UINT16_C(55054), UINT16_C( 7356), UINT16_C(14049), UINT16_C( 6702), UINT16_C(28403), UINT16_C(51425), UINT16_C( 7031) } },
    { { UINT16_C(64700), UINT16_C(53840), UINT16_C(30293), UINT16_C(24633), UINT16_C(41213), UINT16_C(58131), UINT16_C(47653), UINT16_C(50903) },
      { UINT16_C(14710), UINT16_C(24330), UINT16_C(22550), UINT16_C(41482), UINT16_C(39817), UINT16_C( 4036), UINT16_C(  359), UINT16_C(15937) } },
    { { UINT16_C(33041), UINT16_C(60544), UINT16_C(16391), UINT16_C(20282), UINT16_C(61315), UINT16_C(57128), UINT16_C(23303), UINT16_C(  212) },
      { UINT16_C(24243), UINT16_C(35281), UINT16_C(50893), UINT16_C(51963), UINT16_C( 8746), UINT16_C( 5665), UINT16_C(26965), UINT16_C(10863) } },
    { { UINT16_C(13231), UINT16_C( 4020), UINT16_C(50814), UINT16_C(54230), UINT16_C(20073), UINT16_C(49489), UINT16_C(56614), UINT16_C(64602) },
      { UINT16_C( 4798), UINT16_C(38528), UINT16_C(17581), UINT16_C(61879), UINT16_C(37344), UINT16_C(32487), UINT16_C(56075), UINT16_C(61056) } }
  };

static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec_u32[] = {
    { { UINT32_C(1350009498), UINT32_C(    725400), UINT32_C(2805724889), UINT32_C(1764924475) },
      { UINT32_C(3211742472), UINT32_C(3455002506), UINT32_C(1328272682), UINT32_C( 376981289) } },
    { { UINT32_C(1219836757), UINT32_C(3730949730), UINT32_C( 659930880), UINT32_C(3505000130) },
      { UINT32_C( 457628468), UINT32_C(1216432712), UINT32_C( 923586716), UINT32_C( 689602393) } },
    { { UINT32_C(2119447821), UINT32_C(2833496981), UINT32_C(1915130098), UINT32_C(2475037761) },
      { UINT32_C(1964018109), UINT32_C(1004871131), UINT32_C( 764233283), UINT32_C( 588842000) } },
    { { UINT32_C(3167485623), UINT32_C( 152469028), UINT32_C(1805830802), UINT32_C(3963110543) },
      { UINT32_C( 743789470), UINT32_C( 833205332), UINT32_C( 191484176), UINT32_C(4199994711) } },
    { { UINT32_C(1891076670), UINT32_C(1475274943), UINT32_C(3431053427), UINT32_C(3910744858) },
      { UINT32_C( 388796665), UINT32_C( 551801315), UINT32_C( 820693303), UINT32_C( 386743955) } },
    { { UINT32_C( 175169697), UINT32_C(3619925079), UINT32_C(1033174215), UINT32_C(1876682027) },
      { UINT32_C(1481974712), UINT32_C( 682358493), UINT32_C( 415052955), UINT32_C(3574834500) } },
    { { UINT32_C(1554172448), UINT32_C(4131905192), UINT32_C(2031877179), UINT32_C( 796906543) },
      { UINT32_C(1162586168), UINT32_C(1401713093), UINT32_C(  30258736), UINT32_C(  17127378) } },
    { { UINT32_C(4125131360), UINT32_C(2340325563), UINT32_C(1730040803), UINT32_C(2920187641) },
      { UINT32_C(1063166446), UINT32_C(1375759182), UINT32_C(2215804005), UINT32_C(1401116497) } }
  };

  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec_u64[] = {
    { { UINT64_C( 1131307788198894989), UINT64_C( 4345049016526847266) },
      { UINT64_C( 4314999726010705161), UINT64_C(17538192624143051653) } },
    { { UINT64_C(16388179031110353029), UINT64_C(17614050823318144135) },
      { UINT64_C( 5106825994497068575), UINT64_C(17504843500321558050) } },
    { { UINT64_C( 9829005615069038077), UINT64_C(13680678039315968188) },
      { UINT64_C(10159236881913980621), UINT64_C(14413171897621858167) } },
    { { UINT64_C(16105716167654322853), UINT64_C( 4884311171677173098) },
      { UINT64_C(14338163689308608351), UINT64_C(15451179562503354064) } },
    { { UINT64_C( 7404394330613162063), UINT64_C(17801178677532843802) },
      { UINT64_C(  637518372502361975), UINT64_C(16137960790442143473) } },
    { { UINT64_C( 8663552486189264150), UINT64_C( 1206349957516214818) },
      { UINT64_C( 9386313623028586162), UINT64_C( 9922520139715698552) } },
    { { UINT64_C( 9948313469320390530), UINT64_C( 9511068139341768325) },
      { UINT64_C( 4470652107566361934), UINT64_C(15796400244165642313) } },
    { { UINT64_C( 7521705919092506545), UINT64_C(  549235949976352989) },
      { UINT64_C(15753889872705654480), UINT64_C(13458690406980115951) } }
  };

TEST(sub, vrsubhn)
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
        int8x8_t  rst = vrsubhn_s16(a, b);
        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_i8(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f2(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s32) / sizeof(test_vec_s32[0])) ; i++) {
        int32x4_t a = vld1q_s32(test_vec_s32[i].a);
        int32x4_t b = vld1q_s32(test_vec_s32[i].b);
        int16x4_t rst = vrsubhn_s32(a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_i16(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f3(){

    for (size_t i = 0 ; i < (sizeof(test_vec_s64) / sizeof(test_vec_s64[0])) ; i++) {
        int64x2_t a = vld1q_s64(test_vec_s64[i].a);
        int64x2_t b = vld1q_s64(test_vec_s64[i].b);
        int32x2_t rst = vrsubhn_s64(a, b);

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_i32(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f4(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u16) / sizeof(test_vec_u16[0])) ; i++) {
        uint16x8_t a = vld1q_u16(test_vec_u16[i].a);
        uint16x8_t b = vld1q_u16(test_vec_u16[i].b);
        uint8x8_t  rst = vrsubhn_u16(a, b);

        printf("{ ");
        for(int j = 0;j < 8;j ++){
            test_codegen_u8(rst[j]);
            if(j != 7)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f5(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u32) / sizeof(test_vec_u32[0])) ; i++) {
        uint32x4_t a = vld1q_u32(test_vec_u32[i].a);
        uint32x4_t b = vld1q_u32(test_vec_u32[i].b);
        uint16x4_t rst = vrsubhn_u32(a, b);

        printf("{ ");
        for(int j = 0;j < 4;j ++){
            test_codegen_u16(rst[j]);
            if(j != 3)printf(", ");
        }
        printf(" }\n");
    }
    
}

void f6(){

    for (size_t i = 0 ; i < (sizeof(test_vec_u64) / sizeof(test_vec_u64[0])) ; i++) {
        uint64x2_t a = vld1q_u64(test_vec_u64[i].a);
        uint64x2_t b = vld1q_u64(test_vec_u64[i].b);
        uint32x2_t rst = vrsubhn_u64(a, b);;

        printf("{ ");
        for(int j = 0;j < 2;j ++){
            test_codegen_u32(rst[j]);
            if(j != 1)printf(", ");
        }
        printf(" }\n");
    }
    
}