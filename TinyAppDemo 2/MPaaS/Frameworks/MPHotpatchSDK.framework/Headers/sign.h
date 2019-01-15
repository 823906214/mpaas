//
//  Sign.h
//  APMobileSecurity
//
//  Created by wenbi on 14-7-17.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#ifndef APMobileSecurity_Sign_h
#define APMobileSecurity_Sign_h

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 保证钱包安全，需要对敏感文件进行签名和验签，
     * 公钥用于验签，私钥用于签名，读取公钥文件，拿到公钥key
     *
     * @param path 公钥文件路径
     *
     * @return (int) 读取公钥key
     */
    int APSecInitPublicKey(const char *path);
    
    /**
     * 验签Manifest文件
     *
     * @param path 需要验签Manifest文件路径
     * @param sigbuf 签名数据首地址
     * @param siglen 签名数据长度
     *
     * @return (int) 验签结果
     */
    int APSecVerifyManifest(const char *path, const void *sigbuf, size_t siglen);
    
    /**
     * 验签文件
     *
     * @param path 需要验签文件路径
     * @param sigbuf 签名数据首地址
     * @param siglen 签名数据长度
     *
     * @return (int) 验签结果
     */
    int APSecVerifyFile(const char *path, const void *sigbuf, size_t siglen);
    
    //int APSecVerify

    
#ifdef __cplusplus
}
#endif

#endif
