#ifndef __TB_ITF_H__
#define __TB_ITF_H__


#if defined(__cplusplus) || defined(c_plusplus)
#define TBEXTERN_C extern "C"
#else
#define TBEXTERN_C extern 
#endif

#ifdef ANDROID
#define _HYMOBILE
#endif

#ifdef __IPHONE_NA
#ifndef __MAC_NA
#define _HYMOBILE
#endif
#endif

#ifndef _HYMOBILE
#if !(TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
#define _PC
#endif
#endif
/*
#ifdef _PC
#include "cv.h"
#include "highgui.h"
#endif
*/

//SQY:
#define GEN3ON true

#define MAXQRDIMENSION 177

#define TB_STR_SIZE 2048

#define AUTOFOCUS 0
#define DEFOCUS  1

#define HY_RGBA 0
#define HY_YUV 1

#define EAN13 0x1
#define EAN8 0x2
#define UPCA 0x4
#define UPCE 0x8
#define CODE39 0x10
#define CODE128 0x20
#define ITF 0x40
#define EAN14 0X80
#define FASTMAIL ( CODE39 | CODE128 )
#define ONED ( EAN13 | EAN8 | UPCA | UPCE | CODE39 | CODE128 | ITF )
#define QRCODE 0x200
#define DATAMATRIX 0x400
#define HY_4G 0x800

#define HY_4G_LOCAL 0x801
#define HY_4G_SERVER 0x802
#define GEN3 0x8000

#define APCODE 0x10000
//AP Code 有8个子类型， 0是ARcode， 1 预留给小程序，2-7预留
#define APCODE_SUBTYPE_ARCODE (0x00)
#define APCODE_SUBTYPE_XCODE (0x01)
#define APCODE_SUBTYPE_RESVERED_02 (0x02)
#define APCODE_SUBTYPE_RESVERED_03 (0x03)
#define APCODE_SUBTYPE_RESVERED_04 (0x04)
#define APCODE_SUBTYPE_RESVERED_05 (0x05)
#define APCODE_SUBTYPE_RESVERED_06 (0x06)
#define APCODE_SUBTYPE_RESVERED_07 (0x07)


#define HY_MINIMUM_FEATURE 36

//#define ALLCODE ( ONED | QRCODE | DATAMATRIX)
#define ALLCODE ( ONED | QRCODE | DATAMATRIX | GEN3)

//reserved for HYSDK
#define HYSDK_NET_LOGO  0x01000000
#define HYSDK_RESERVED1 0x02000000
#define HYSDK_RESERVED2 0x04000000
#define HYSDK_RESERVED3 0x08000000
#define HYSDK_RESERVED4 0x10000000
#define HYSDK_RESERVED5 0x20000000
#define HYSDK_RESERVED6 0x40000000
#define HYSDK_RESERVED7 0x80000000


//switcher
#define MA_SDK_QR_OFF
#define MA_SDK_BARCODE_OFF
#define NEW_QR_ENGINE_ON
typedef signed int TBInt;
typedef signed char TBChar;
typedef unsigned char TBUChar;

#define AUTO_SIZE 480

#define TBAR_DEBUG 0
#define TBAR_SVAEIMAGE 0

#ifndef MAX
#define MAX(a, b)  ((a)>(b)?(a):(b))
#endif

#ifndef MIN
#define MIN(a, b)  ((a)<(b)?(a):(b))
#endif

#ifndef FLT_EPSILON
#define FLT_EPSILON 1.192092896e-07F
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define TDEBUG 0

typedef struct {
    TBInt x;
    TBInt y;
    TBInt width;
    TBInt height;
} TBarRect;

// The format of TBarImage MUST be BGRA(8888)
typedef struct {
    TBInt width;
    TBInt height;
    TBInt bytesPerRow;
    TBarRect cropRect;
    TBInt format;
    TBInt resample;
    TBUChar *data;
//    char addr[1024];
#ifdef ANDROID
    char* str4GLocalAddr;
#endif
} TBarImage;

#ifdef SCANNER_DEBUG
typedef struct {
    size_t len;
    int points[200][2];
} Points;
#endif
typedef struct {
    TBInt type;             //0:unknown 1:barcode 2:qrcode //这是假的，别上当
    TBInt subType;          //depend on 'type'.
    TBChar str[TB_STR_SIZE];//null-terminated string for decoding info
#ifdef __ANDROID__
    TBInt avgGray;          //average gray
#endif

    float codeProportion;
    int version;
    char ecLevel;
    int bitErrors;
#ifdef SCANNER_DEBUG
    Points tried, possible, guess;
#endif

    TBarRect rect;          //hot area

#ifndef ALIPAY_DEPRECATED
    TBInt x[4], y[4];
    TBInt dir;
    TBChar bitstream[MAXQRDIMENSION * MAXQRDIMENSION];
    //SQY in the old version . sometimes ,we use subtype to send the dimension of the bitstream , now we separate them ,
    // we use TBInt dimension
    TBInt dimension;
    //SQY since we merge GEN2 into this SDK ,so we create hiddenData to save the gen2Result.
    TBChar hiddenData[TB_STR_SIZE];
#endif
} TBarRet;

#define POSITIVE_PROBABILITY 60 // 扫条码先正向后逆向的概率
#define MAX_PROBABLE_NUM 4
#define MAX_CHARACTER_NUM 100

#define MAX_ROW_LEN 2048
#define MAX_MEMORY_SIZE (MAX_ROW_LEN*MAX_ROW_LEN)
#ifdef ANDROID
#define BARCODE_STEP_NUM_OF_TRYHARD_2 200
#define BARCODE_STEP_NUM_OF_TRYHARD_1 60
#else
#define BARCODE_STEP_NUM_OF_TRYHARD_2 200
#define BARCODE_STEP_NUM_OF_TRYHARD_1 60
#endif
#define BARCODE_THRESHOLD_LEN 7
typedef struct BarcodeResult {
    char string[MAX_CHARACTER_NUM];
    int count; // 用于条形码算法策略统计
    int type;
    int subType;

#ifndef ALIPAY_DEPRECATED
    TBInt dir;
    TBarRect rect;
#endif
} BARCODERESULT;


// Init
//TBEXTERN_C TBInt TBDecodeInit(int width, int height, TBarRect cropRect);

// image: image info provided by camera
// ret: decoded data return form decoder. ret may be NULL.
// return: 1: success
TBEXTERN_C TBInt TBDecode(const TBarImage *image, TBarRet *ret, TBInt inCount, TBInt *outCount, int ScanMode);
TBEXTERN_C TBInt TBDecode_Test(const TBarImage *image, TBarRet *ret, TBInt inCount, TBInt *outCount, int ScanMode);

TBEXTERN_C TBInt TBDecodeBigImage(const TBarImage *image, TBarRet *ret, TBInt inCount, TBInt *outCount, int scanMode);
//TBEXTERN_C TBarRet TBDecodeBigImage(const TBarImage* image);


TBEXTERN_C TBInt startCameraDecodeWithRect(TBInt width, TBInt height, int zoom);
TBEXTERN_C TBInt endCameraDecode();

TBEXTERN_C TBInt configDecode(const int argn, const char **argv);

//TBEXTERN_C void ReleaseMemory();
#endif // __TB_ITF_H__
