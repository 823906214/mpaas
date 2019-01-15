## chooseImage (拍照/选择照片)
### 示例
```
AlipayJSBridge.call('chooseImage', {
  sourceType: ['camera','album'],
  count: 5  
}, function (result) {
});
```

### 参数

| 名称 |	类型 |描述 | 可选 | 默认值 | 版本 |
|:----|:----|:----|:----|:----|:----|
| count | int | 最大可选照片数 | Y | 默认1张，上限9张 | 9.9.7 |
| sourceType  | array | 相册选取或者拍照 | Y | ['camera','album'] | 9.9.7 |
| publicDomain | bool | 返回开放域LocalId(上传后外部可访问) | Y | false | 10.0.5 |

### 结果
| 名称 | 类型 | 说明 |
|:----|:----|:----|
| localIds | array | 图片多媒体LocalId iOS使用 |
| tempFilePath | array | 图片文件路径 Android使用 |
| success | bool | 是否成功返回 | 
| error | string | 错误码 |
| errorMessage | string | 错误描述 |

### 错误码描述

```
2	参数出错
3	未知错误
11 	用户取消
```