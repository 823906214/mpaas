(function(self){'use strict';var support={searchParams:'URLSearchParams'in self,iterable:'Symbol'in self&&'iterator'in Symbol,blob:'FileReader'in self&&'Blob'in self&&(function(){try{new Blob()
return true}catch(e){return false}})(),formData:'FormData'in self,arrayBuffer:'ArrayBuffer'in self}
if(support.arrayBuffer){var viewClasses=['[object Int8Array]','[object Uint8Array]','[object Uint8ClampedArray]','[object Int16Array]','[object Uint16Array]','[object Int32Array]','[object Uint32Array]','[object Float32Array]','[object Float64Array]']
var isDataView=function(obj){return obj&&DataView.prototype.isPrototypeOf(obj)}
var isArrayBufferView=ArrayBuffer.isView||function(obj){return obj&&viewClasses.indexOf(Object.prototype.toString.call(obj))>-1}}
function normalizeName(name){if(typeof name!=='string'){name=String(name)}
if(/[^a-z0-9\-#$%&'*+.\^_`|~]/i.test(name)){throw new TypeError('Invalid character in header field name')}
return name.toLowerCase()}
function normalizeValue(value){if(typeof value!=='string'){value=String(value)}
return value}
function iteratorFor(items){var iterator={next:function(){var value=items.shift()
return{done:value===undefined,value:value}}}
if(support.iterable){iterator[Symbol.iterator]=function(){return iterator}}
return iterator}
function Headers(headers){this.map={}
if(headers instanceof Headers){headers.forEach(function(value,name){this.append(name,value)},this)}else if(Array.isArray(headers)){headers.forEach(function(header){this.append(header[0],header[1])},this)}else if(headers){Object.getOwnPropertyNames(headers).forEach(function(name){this.append(name,headers[name])},this)}}
Headers.prototype.append=function(name,value){name=normalizeName(name)
value=normalizeValue(value)
var oldValue=this.map[name]
this.map[name]=oldValue?oldValue+','+value:value}
Headers.prototype['delete']=function(name){delete this.map[normalizeName(name)]}
Headers.prototype.get=function(name){name=normalizeName(name)
return this.has(name)?this.map[name]:null}
Headers.prototype.has=function(name){return this.map.hasOwnProperty(normalizeName(name))}
Headers.prototype.set=function(name,value){this.map[normalizeName(name)]=normalizeValue(value)}
Headers.prototype.forEach=function(callback,thisArg){for(var name in this.map){if(this.map.hasOwnProperty(name)){callback.call(thisArg,this.map[name],name,this)}}}
Headers.prototype.keys=function(){var items=[]
this.forEach(function(value,name){items.push(name)})
return iteratorFor(items)}
Headers.prototype.values=function(){var items=[]
this.forEach(function(value){items.push(value)})
return iteratorFor(items)}
Headers.prototype.entries=function(){var items=[]
this.forEach(function(value,name){items.push([name,value])})
return iteratorFor(items)}
if(support.iterable){Headers.prototype[Symbol.iterator]=Headers.prototype.entries}
function consumed(body){if(body.bodyUsed){return Promise.reject(new TypeError('Already read'))}
body.bodyUsed=true}
function fileReaderReady(reader){return new Promise(function(resolve,reject){reader.onload=function(){resolve(reader.result)}
reader.onerror=function(){reject(reader.error)}})}
function readBlobAsArrayBuffer(blob){var reader=new FileReader()
var promise=fileReaderReady(reader)
reader.readAsArrayBuffer(blob)
return promise}
function readBlobAsText(blob){var reader=new FileReader()
var promise=fileReaderReady(reader)
reader.readAsText(blob)
return promise}
function readArrayBufferAsText(buf){var view=new Uint8Array(buf)
var chars=new Array(view.length)
for(var i=0;i<view.length;i++){chars[i]=String.fromCharCode(view[i])}
return chars.join('')}
function bufferClone(buf){if(buf.slice){return buf.slice(0)}else{var view=new Uint8Array(buf.byteLength)
view.set(new Uint8Array(buf))
return view.buffer}}
function Body(){this.bodyUsed=false
this._initBody=function(body){this._bodyInit=body
if(!body){this._bodyText=''}else if(typeof body==='string'){this._bodyText=body}else if(support.blob&&Blob.prototype.isPrototypeOf(body)){this._bodyBlob=body}else if(support.formData&&FormData.prototype.isPrototypeOf(body)){this._bodyFormData=body}else if(support.searchParams&&URLSearchParams.prototype.isPrototypeOf(body)){this._bodyText=body.toString()}else if(support.arrayBuffer&&support.blob&&isDataView(body)){this._bodyArrayBuffer=bufferClone(body.buffer)
this._bodyInit=new Blob([this._bodyArrayBuffer])}else if(support.arrayBuffer&&(ArrayBuffer.prototype.isPrototypeOf(body)||isArrayBufferView(body))){this._bodyArrayBuffer=bufferClone(body)}else{throw new Error('unsupported BodyInit type')}
if(!this.headers.get('content-type')){if(typeof body==='string'){this.headers.set('content-type','text/plain;charset=UTF-8')}else if(this._bodyBlob&&this._bodyBlob.type){this.headers.set('content-type',this._bodyBlob.type)}else if(support.searchParams&&URLSearchParams.prototype.isPrototypeOf(body)){this.headers.set('content-type','application/x-www-form-urlencoded;charset=UTF-8')}}}
if(support.blob){this.blob=function(){var rejected=consumed(this)
if(rejected){return rejected}
if(this._bodyBlob){return Promise.resolve(this._bodyBlob)}else if(this._bodyArrayBuffer){return Promise.resolve(new Blob([this._bodyArrayBuffer]))}else if(this._bodyFormData){throw new Error('could not read FormData body as blob')}else{return Promise.resolve(new Blob([this._bodyText]))}}
this.arrayBuffer=function(){if(this._bodyArrayBuffer){return consumed(this)||Promise.resolve(this._bodyArrayBuffer)}else{return this.blob().then(readBlobAsArrayBuffer)}}}
this.text=function(){var rejected=consumed(this)
if(rejected){return rejected}
if(this._bodyBlob){return readBlobAsText(this._bodyBlob)}else if(this._bodyArrayBuffer){return Promise.resolve(readArrayBufferAsText(this._bodyArrayBuffer))}else if(this._bodyFormData){throw new Error('could not read FormData body as text')}else{return Promise.resolve(this._bodyText)}}
if(support.formData){this.formData=function(){return this.text().then(decode)}}
this.json=function(){return this.text().then(JSON.parse)}
return this}
var methods=['DELETE','GET','HEAD','OPTIONS','POST','PUT']
function normalizeMethod(method){var upcased=method.toUpperCase()
return(methods.indexOf(upcased)>-1)?upcased:method}
function Request(input,options){options=options||{}
var body=options.body
if(input instanceof Request){if(input.bodyUsed){throw new TypeError('Already read')}
this.url=input.url
this.credentials=input.credentials
if(!options.headers){this.headers=new Headers(input.headers)}
this.method=input.method
this.mode=input.mode
if(!body&&input._bodyInit!=null){body=input._bodyInit
input.bodyUsed=true}}else{this.url=String(input)}
this.credentials=options.credentials||this.credentials||'omit'
if(options.headers||!this.headers){this.headers=new Headers(options.headers)}
this.method=normalizeMethod(options.method||this.method||'GET')
this.mode=options.mode||this.mode||null
this.referrer=null
if((this.method==='GET'||this.method==='HEAD')&&body){throw new TypeError('Body not allowed for GET or HEAD requests')}
this._initBody(body)}
Request.prototype.clone=function(){return new Request(this,{body:this._bodyInit})}
function decode(body){var form=new FormData()
body.trim().split('&').forEach(function(bytes){if(bytes){var split=bytes.split('=')
var name=split.shift().replace(/\+/g,' ')
var value=split.join('=').replace(/\+/g,' ')
form.append(decodeURIComponent(name),decodeURIComponent(value))}})
return form}
function parseHeaders(rawHeaders){var headers=new Headers()
var preProcessedHeaders=rawHeaders.replace(/\r?\n[\t ]+/g,' ')
preProcessedHeaders.split(/\r?\n/).forEach(function(line){var parts=line.split(':')
var key=parts.shift().trim()
if(key){var value=parts.join(':').trim()
headers.append(key,value)}})
return headers}
Body.call(Request.prototype)
function Response(bodyInit,options){if(!options){options={}}
this.type='default'
this.status=options.status===undefined?200:options.status
this.ok=this.status>=200&&this.status<300
this.statusText='statusText'in options?options.statusText:'OK'
this.headers=new Headers(options.headers)
this.url=options.url||''
this._initBody(bodyInit)}
Body.call(Response.prototype)
Response.prototype.clone=function(){return new Response(this._bodyInit,{status:this.status,statusText:this.statusText,headers:new Headers(this.headers),url:this.url})}
Response.error=function(){var response=new Response(null,{status:0,statusText:''})
response.type='error'
return response}
var redirectStatuses=[301,302,303,307,308]
Response.redirect=function(url,status){if(redirectStatuses.indexOf(status)===-1){throw new RangeError('Invalid status code')}
return new Response(null,{status:status,headers:{location:url}})}
self.Headers=Headers
self.Request=Request
self.Response=Response
self.fetch=function(input,init){return new Promise(function(resolve,reject){var request=new Request(input,init)
var xhr=new XMLHttpRequest()
xhr.onload=function(){var options={status:xhr.status,statusText:xhr.statusText,headers:parseHeaders(xhr.getAllResponseHeaders()||'')}
options.url='responseURL'in xhr?xhr.responseURL:options.headers.get('X-Request-URL')
var body='response'in xhr?xhr.response:xhr.responseText
resolve(new Response(body,options))}
xhr.onerror=function(){reject(new TypeError('Network request failed'))}
xhr.ontimeout=function(){reject(new TypeError('Network request failed'))}
xhr.open(request.method,request.url,true)
if(request.credentials==='include'){xhr.withCredentials=true}else if(request.credentials==='omit'){xhr.withCredentials=false}
if('responseType'in xhr&&support.blob){xhr.responseType='blob'}
request.headers.forEach(function(value,name){xhr.setRequestHeader(name,value)})
xhr.send(typeof request._bodyInit==='undefined'?null:request._bodyInit)})}
self.fetch.polyfill=true})(typeof self!=='undefined'?self:this);(function(){var k_r_submitter=/^(?:submit|button|image|reset|file)$/i;var k_r_success_contrls=/^(?:input|select|textarea|keygen)/i;var brackets=/(\[[^\[\]]*\])/g;function serialize(form,options){if(typeof options!='object'){options={hash:!!options};}
else if(options.hash===undefined){options.hash=true;}
var result=(options.hash)?{}:'';var serializer=options.serializer||((options.hash)?hash_serializer:str_serialize);var elements=form&&form.elements?form.elements:[];var radio_store=Object.create(null);for(var i=0;i<elements.length;++i){var element=elements[i];if((!options.disabled&&element.disabled)||!element.name){continue;}
if(!k_r_success_contrls.test(element.nodeName)||k_r_submitter.test(element.type)){continue;}
var key=element.name;var val=element.value;if((element.type==='checkbox'||element.type==='radio')&&!element.checked){val=undefined;}
if(options.empty){if(element.type==='checkbox'&&!element.checked){val='';}
if(element.type==='radio'){if(!radio_store[element.name]&&!element.checked){radio_store[element.name]=false;}
else if(element.checked){radio_store[element.name]=true;}}
if(val==undefined&&element.type=='radio'){continue;}}
else{if(!val){continue;}}
if(element.type==='select-multiple'){val=[];var selectOptions=element.options;var isSelectedOptions=false;for(var j=0;j<selectOptions.length;++j){var option=selectOptions[j];var allowedEmpty=options.empty&&!option.value;var hasValue=(option.value||allowedEmpty);if(option.selected&&hasValue){isSelectedOptions=true;if(options.hash&&key.slice(key.length-2)!=='[]'){result=serializer(result,key+'[]',option.value);}
else{result=serializer(result,key,option.value);}}}
if(!isSelectedOptions&&options.empty){result=serializer(result,key,'');}
continue;}
result=serializer(result,key,val);}
if(options.empty){for(var key in radio_store){if(!radio_store[key]){result=serializer(result,key,'');}}}
return result;}
function parse_keys(string){var keys=[];var prefix=/^([^\[\]]*)/;var children=new RegExp(brackets);var match=prefix.exec(string);if(match[1]){keys.push(match[1]);}
while((match=children.exec(string))!==null){keys.push(match[1]);}
return keys;}
function hash_assign(result,keys,value){if(keys.length===0){result=value;return result;}
var key=keys.shift();var between=key.match(/^\[(.+?)\]$/);if(key==='[]'){result=result||[];if(Array.isArray(result)){result.push(hash_assign(null,keys,value));}
else{result._values=result._values||[];result._values.push(hash_assign(null,keys,value));}
return result;}
if(!between){result[key]=hash_assign(result[key],keys,value);}
else{var string=between[1];var index=+string;if(isNaN(index)){result=result||{};result[string]=hash_assign(result[string],keys,value);}
else{result=result||[];result[index]=hash_assign(result[index],keys,value);}}
return result;}
function hash_serializer(result,key,value){var matches=key.match(brackets);if(matches){var keys=parse_keys(key);hash_assign(result,keys,value);}
else{var existing=result[key];if(existing){if(!Array.isArray(existing)){result[key]=[existing];}
result[key].push(value);}
else{result[key]=value;}}
return result;}
function str_serialize(result,key,value){value=value.replace(/(\r)?\n/g,'\r\n');value=encodeURIComponent(value);value=value.replace(/%20/g,'+');return result+(result?'&':'')+encodeURIComponent(key)+'='+value;}
window.NebulaSerialize=serialize;})();(function(){function onDOMReady(callback){var readyRE=/complete|loaded|interactive/;if(readyRE.test(document.readyState)){setTimeout(function(){callback();},1);}else{document.defaultView.addEventListener('DOMContentLoaded',function(){callback();},false);}}
onDOMReady(function(){var cookieOriginSetter=document.__lookupSetter__('cookie'),cookieOriginGetter=document.__lookupGetter__('cookie');if(cookieOriginSetter&&cookieOriginGetter){Object.defineProperty(document,'cookie',{set:function(cookstr){var message={};message[msgType]="cookie";message["cookie"]=cookstr;message["url"]=document.URL;window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);cookieOriginSetter.apply(document,[cookstr]);},get:function(){return cookieOriginGetter.apply(document,[]);}});}});function getAllHTMLFormData(element,fromAjax){var result=[];if(element.nodeName.toLowerCase()=="form"){var serializeResult=NebulaSerialize(element,{hash:true,empty:true});var inputs=[].slice.call(element.querySelectorAll('input'));for(var i=0;i<inputs.length;i++){var field=inputs[i];var type=field.type,name=field.name;if(type=='file'&&field.files&&field.files.length>0){var filesLength=field.files.length;for(var j=0;j<filesLength;j++){if((element.enctype.toLowerCase()=="application/x-www-form-urlencoded"||element.enctype.toLowerCase()=="text/plain")&&!fromAjax){result.push({"name":name,"value":field.files[j].name});}else if(formElemntList[name]&&formElemntList[name][j]){result.push({"name":name,"value":formElemntList[name][j]});}else{result.push({"name":name,"value":field.files[j]});}}}}
for(var key in serializeResult){if(serializeResult.hasOwnProperty(key)){result.push({"name":key,"value":serializeResult[key]});}}}
return result;}
function serializeFormData(data){return new Promise(function(resolve,reject){var dataVal=data["value"];if(typeof(dataVal)==="string"){resolve(data);}else if(dataVal instanceof Blob||dataVal instanceof File){var reader=new FileReader();reader.onload=function(event){var result=event.target.result;if(result.length>0){data["value"]=result;resolve(data);}else{reject(new Error(""));}}
reader.onerror=function(){reject(new Error(""));}
reader.onabort=function(){reject(new Error(""));}
reader.readAsDataURL(dataVal);}else{resolve(data);}});}
function arrayBufferToBase64(buffer){var binary='';var bytes=new Uint8Array(buffer);var len=bytes.byteLength;for(var i=0;i<len;i++){binary+=String.fromCharCode(bytes[i]);}
return window.btoa(binary);}
var serializeData=function(data,callback){var reader=new FileReader();reader.onload=function(event){var result=event.target.result;callback(result);}
reader.readAsDataURL(data);}
function recordError(error){if(error instanceof Error){var message={};message[msgType]="error";message["errorInfo"]=error.message;window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}}
function addFormExtraInfoWithElement(element){var item=element;if(item.method&&item.method.toLowerCase()==="get"){return;}
var radom=(+new Date())+""+Math.round((Math.random()*(100000)));var hiddenElement=element.querySelector('input[name=X-NEBULAXMLHTTPREQUEST]');if(hiddenElement){hiddenElement.setAttribute("value",radom);}else{hiddenElement=document.createElement("input");hiddenElement.setAttribute("type","hidden");hiddenElement.setAttribute("name","X-NEBULAXMLHTTPREQUEST");hiddenElement.setAttribute("value",radom);item.appendChild(hiddenElement);}
var methodUrl=item.getAttribute("action");if(!/X-NEBULAXMLHTTPREQUEST/.test(methodUrl)){var urlParse=document.createElement('a');urlParse.href=methodUrl;if(urlParse.search&&urlParse.search.length>0){item.setAttribute("action",urlParse.protocol+"//"+urlParse.host+urlParse.pathname+urlParse.search+"&X-NEBULAXMLHTTPREQUEST="+radom+urlParse.hash);}else{item.setAttribute("action",urlParse.protocol+"//"+urlParse.host+urlParse.pathname+"?X-NEBULAXMLHTTPREQUEST="+radom+urlParse.hash)}}else{item.setAttribute("action",methodUrl.replace(/X-NEBULAXMLHTTPREQUEST=(\d+)/,"X-NEBULAXMLHTTPREQUEST="+radom));}
item.setAttribute("data-nebulaId",radom);}
function addFormExtraInfoToElement(){var forms=[].slice.call(document.querySelectorAll("form"));for(var i=forms.length-1;i>=0;i--){addFormExtraInfoWithElement(forms[i]);}}
var FakeFormData=(function(fn){window.originFormData=fn;return function(form){this.realFormData=new fn(form);if(form){this.targetForm=form;}
this.appendData=[];}})(FormData);FakeFormData.prototype.constructor=window.originFormData;FakeFormData.prototype.append=function(name,value,filename){this.appendData.push({"name":name,"value":value,"filename":filename});}
FormData=FakeFormData;var messageList={};var msgId="msgId",msgCookie="msgCookie",msgMainUrl="msgMainUrl",msgRequestUrl="msgRequestUrl",msgVal="val",msgType='type',msgEnctype='FormEnctype',msgAcceptCharset="AcceptCharset",msgErrorMessage="errorMessage",msgDocumentCharset="DocumentCharset",msgIsStream="IsStream";var NEBULAXMLHTTPREQUESTMESSAGEHANDLER={cacheMessage:function(xmlhttprequest,callFn,args,msgId){messageList[msgId]={msgId:msgId,callBack:function(){var that=xmlhttprequest;try{return callFn.apply(that,args);}catch(ex){recordError(ex);}}};setTimeout(function(){NEBULAXMLHTTPREQUESTMESSAGEHANDLER.triggerMessageCallBack(msgId);},500);},triggerMessageCallBack:function(msgId){if(messageList[msgId]){messageList[msgId]["callBack"]();delete messageList[msgId];}},addFormExtraInfoToElement:function(){var message={};message[msgType]="FormElement";var element=getFormWithElement(window.lastClickElement);if(element.method&&element.method.toLowerCase()==="get"){return;}
if(element){var datas=getAllHTMLFormData(element,false);Promise.all(datas.map(function(data){return serializeFormData(data);})).then(function(value){message[msgVal]=value;message[msgType]="FormElement";message[msgEnctype]=element.enctype;message[msgAcceptCharset]=element.acceptCharset;message[msgDocumentCharset]=document.charset;window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}).catch(function(error){recordError(error);});return element.getAttribute("data-nebulaId");}}}
window.NebulaXMLHttpRequestMessageBridge=NEBULAXMLHTTPREQUESTMESSAGEHANDLER;XMLHttpRequest.prototype.open=(function(fn){return function(method,url,async,username,password){this.requestAsync=(async===false?false:true);var radom=(+new Date())+""+Math.round((Math.random()*(100000)));this.requestId=radom;if(method&&method.toLowerCase()=="post"){if(!/X-NEBULAXMLHTTPREQUEST/.test(url)){var urlParse=document.createElement('a');urlParse.href=url;if(urlParse.search&&urlParse.search.length>0){url=urlParse.protocol+"//"+urlParse.host+urlParse.pathname+urlParse.search+"&X-NEBULAXMLHTTPREQUEST="+radom+urlParse.hash;}else{url=urlParse.protocol+"//"+urlParse.host+urlParse.pathname+"?X-NEBULAXMLHTTPREQUEST="+radom+urlParse.hash;}}else{url=url.replace(/X-NEBULAXMLHTTPREQUEST=(\d+)/,"X-NEBULAXMLHTTPREQUEST="+radom);}}
this.requestUrl=url;return fn.apply(this,[method,url,async,username,password]);}})(XMLHttpRequest.prototype.open);XMLHttpRequest.prototype.send=(function(fn){return function(e){var radom=this.requestId;var message={};var that=this;var args=[].slice.call(arguments);message[msgId]=radom;message[msgMainUrl]=document.URL;message[msgRequestUrl]=this.requestUrl;if(!e){return fn.apply(this,args);}else if(typeof(e)==='string'&&e.length>0){message[msgVal]=e;message[msgType]="String";window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}else if(e instanceof Blob){message[msgType]="Blob";if(this.requestAsync){serializeData(e,function(result){message[msgVal]=result;window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);NEBULAXMLHTTPREQUESTMESSAGEHANDLER.cacheMessage(that,fn,args,radom);});return;}else{message["error"]="NOTSUPPORT";window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}}else if(e instanceof FormData){message[msgType]="FormData";if(this.requestAsync){message[msgType]="FormData";var datas=e.appendData;if(e.targetForm){datas=datas.concat(getAllHTMLFormData(e.targetForm,true));}
Promise.all(datas.map(function(data){return serializeFormData(data);})).then(function(value){message[msgVal]=value;window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);NEBULAXMLHTTPREQUESTMESSAGEHANDLER.cacheMessage(that,fn,e.realFormData,radom);}).catch(function(error){recordError(error);})
return;}else{message["error"]="NOTSUPPORT";window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}}else if(e.nodeType){message[msgType]="Document";if(e===document){message[msgVal]=(new XMLSerializer()).serializeToString(document);}else{message[msgVal]=e.toString();}
window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}else if(e instanceof ArrayBuffer){message[msgVal]=arrayBufferToBase64(e);message[msgType]="ArrayBuffer";window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}else if(e.buffer){message[msgVal]=arrayBufferToBase64(e.buffer);message[msgType]="ArrayBuffer";window.webkit.messageHandlers.PSDXMLHTTPREQUESTMESSAGE.postMessage(message);}else{return fn.apply(this,args);}
if(this.requestAsync){return NEBULAXMLHTTPREQUESTMESSAGEHANDLER.cacheMessage(that,fn,args,radom);}else{return fn.apply(this,args);}}})(XMLHttpRequest.prototype.send);var formElemntList={};window.lastClickElement=null;function getFormWithElement(element){if(element&&element.nodeType){var parentNode=element;while(parentNode){if(parentNode.nodeName.toLowerCase()==="form"){return parentNode;}else if(parentNode===document||parentNode===document.documentElement||parentNode===document.body){break;}
parentNode=parentNode.parentNode;}
return null;}}
document.addEventListener("DOMContentLoaded",function(){addFormExtraInfoToElement();document.addEventListener("change",function(e){var targetElement=e.target;if(targetElement.nodeName&&targetElement.nodeName.toLowerCase()&&targetElement.type&&targetElement.type==="file"){var that=targetElement;for(var i=0;i<that.files.length;i++){(function(fileItem){serializeFormData({name:that.name,value:fileItem}).then(function(value){if(!formElemntList[that.name]){formElemntList[that.name]=[];}
formElemntList[that.name].push({name:that.name,value:value["value"],fileName:fileItem.name});}).catch(function(error){recordError(error);});})(that.files[i])}}},false);document.addEventListener("click",function(e){window.lastClickElement=e.target;},true);},false);HTMLFormElement.prototype.submit=(function(fn){return function(){var that=this;var args=[].slice.call(arguments);var datas=getAllHTMLFormData(this,false);var message={};addFormExtraInfoWithElement(this);window.lastClickElement=this;fn.apply(that,args);}})(HTMLFormElement.prototype.submit);})();