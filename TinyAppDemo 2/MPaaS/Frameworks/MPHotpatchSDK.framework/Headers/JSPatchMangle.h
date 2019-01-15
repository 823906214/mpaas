//
//  JSPatchMangle.h
//  JSHotpatchSDK
//
//  Created by shenmo on 15/02/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#ifndef JSPATCHMANGLE_H
#define JSPATCHMANGLE_H

/*
 Replace all "_OC_" to "_BVJ_"
 
 global.require = function(clsNames) {
    var lastRequire
    clsNames.split(',').forEach(function(clsName) {
        if (clsName == 'JPEngine') {
            clsName = 'BVJMachine'
        }
        lastRequire = _require(clsName.trim())
    })
    return lastRequire
 }
 */

// JP->BVJ, bandage via js
#define MANGLED_MAIN_PREFIX @"BVJ"

#define JSPatchCoreScriptContent BVJCoreContent

#define JSBandageGenerator BVJBandageGenerator
#define startEngine startMachine
#define debugPatchInit debugBandageInit
#define runJSString executeSource
#define runJSFile executeFile

#define _JSOverideMethods _BVJReplacedFunctions
#define _JSMethodSignatureCache _BVJFunctionSignatureCache
#define _JSMethodSignatureLock _BVJFunctionSignatureLock
#define _JSMethodForwardCallLock _BVJFunctionForwardCallLock
#define JPEngine BVJMachine
#define evaluateScriptWithPath loadSourceWithPath
#define _evaluateScriptWithPath _loadSourceWithPath
#define _evaluateScript _loadSource
#define JPEngineProtocol BVJMachineProtocol
#define didReplaceMethodForClass didOverrideFunctionForClass
#define _JPEngineDelegate _BVJMachineDelegate
#define JPBoxing BVJWrapper
#define boxObj wrapObj
#define boxPointer wrapPointer
#define boxClass wrapClass
#define boxWeakObj wrapWeakObj
#define boxAssignObj wrapAssignObj
#define unbox unwrap
#define unboxPointer unwrapPointer
#define unboxClass unwrapClass
#define fixSignature amendSignature
#define jp_methodSignatureForSelector bvj_functionSignatureForSelector
#define jp_fixMethodSignature bvj_amendFunctionSignature
#define defineStruct makeStructDefinition
#define defineProtocol makeProtocolDefinition
#define addGroupMethodsToProtocol appendBatchFunctionsToProtocol
#define addMethodToProtocol appendFunctionToProtocol
#define defineClass makeClassDefinition
#define getJSFunctionInObjectHierachy getBVJFunctionInObjectTree
#define JPForwardInvocation BVJTransmitCall
#define JPExecuteORIGForwardInvocation BVJRunORITransmitCall
#define _initJPOverideMethods _setupBVJReplacedFunctions
#define overrideMethod replaceFunction
#define overideMethods replacedFunctions
#define callSelector invokeSelector
#define invokeVariableParameterMethod callVariadicFunction
#define genCallbackBlock makeCallbackLambda
#define sizeOfStructTypes getStructTypeSize
#define getStructDataWithDict transmitMapToStruct
#define getDictOfStruct transmitStructToMap
#define extractStructName getNameOfStruct
#define blockTypeIsObject lambdaTypeIsObject
#define convertJPSelectorString transmitBVJSelectorString
#define formatOCToJS transmitNativeToBVJ
#define formatJSToOC transmitBVJToNative
#define _formatOCToJSList transmitNativeToBVJArray
#define _unboxOCObjectToJS _unwrapNativeObjectToBVJ
#define JPExtension BVJExtension
#define formatPointerJSToOC transmitPointerBVJToNative
#define formatRetainedCFTypeOCToJS transmitRetainedCFTypeNativeToBVJ
#define formatPointerOCToJS transmitPointerNativeToBVJ
#define getStructDataWidthDict transmitMapToStruct
#define registeredStruct enrolledStruct
#define includedScriptPaths enrolledSourcePaths

// extensions
#define JPDispatchQueue BVJDispatchQueue
#define JPFile BVJFile
#define JPLogger BVJLogger
#define JPNumber BVJNumber
#define JPStruct BVJStruct
#define JPPointer BVJPointer
#define JPCFunction BVJDialer
#define callCFunction do
#define defineCFunction prepare
#define JPMemory BVJMemory
#define JPStructPointer BVJStructPointer
#define JPCleaner BVJCleaner
#define JPLocker BVJLocker

#endif /* JSPATCHMANGLE_H */




