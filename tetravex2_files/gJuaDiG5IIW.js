/*!CK:3076287364!*//*1428291379,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["RbRFM"]); }

__d("legacy:control-textarea",["TextAreaControl"],function(a,b,c,d){b.__markCompiled&&b.__markCompiled();a.TextAreaControl=b('TextAreaControl');},3);
__d("PhotoViewerInitPagelet",["ge","DOM","PhotoSnowlift","PhotoTags","PhotoTagger","PhotoTagApproval"],function(a,b,c,d,e,f,g,h,i,j,k,l){b.__markCompiled&&b.__markCompiled();function m(n){"use strict";i.attachTagger(n.tagging,n.tokenizer);var o=i.getInstance(),p=o.getRoot();new j([g('fbPhotoSnowliftAuthorName'),h.find(p,'span.fbPhotoTagList'),h.find(p,'div.fbPhotoPagesTagList')],g('fbPhotoSnowliftTagBoxes'),n.version);if(n.setupPhotoTagger){var q=new k(o);q.initSnowlift(n.tagging,n.tokenizer,n.userId);q.setQueueName(n.queueName);}new l(o);}e.exports=m;},null);