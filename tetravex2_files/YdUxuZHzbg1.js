/*!CK:3846777431!*//*1425878060,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["ewcw9"]); }

__d("KnowledgeClaimSentimentEnum",[],function(a,b,c,d,e,f){b.__markCompiled&&b.__markCompiled();e.exports={AGREE:"agree",DISAGREE:"disagree",UNSURE:"unsure",SPAM:"spam"};},null);
__d("legacy:animation",["Animation"],function(a,b,c,d){b.__markCompiled&&b.__markCompiled();a.Animation=b('Animation');},3);
__d("MetapageMigratedDialog",["DOMQuery","Event","Input","Button"],function(a,b,c,d,e,f,g,h,i,j){b.__markCompiled&&b.__markCompiled();k.enableConfirm=function(l,m){"use strict";var n=l.map(function(p){return g.find(p,'input');}),o=function(){j.setEnabled(m,n.every(function(p){return !i.isEmpty(p);}));};n.map(function(p){return h.listen(p,'input',o);});};function k(l,m,n,o){"use strict";this.$MetapageMigratedDialog0=l;this.$MetapageMigratedDialog1=m;this.$MetapageMigratedDialog2=n;this.$MetapageMigratedDialog3=o;this.$MetapageMigratedDialog4=[];this.$MetapageMigratedDialog5=[];return this.init();}k.prototype.init=function(){"use strict";this.$MetapageMigratedDialog4.push(h.listen(this.$MetapageMigratedDialog0,'mouseover',(function(l){this.$MetapageMigratedDialog6();this.$MetapageMigratedDialog2.show();return false;}).bind(this)));this.$MetapageMigratedDialog4.push(h.listen(this.$MetapageMigratedDialog0,'mouseout',(function(l){this.$MetapageMigratedDialog7();return false;}).bind(this)));this.$MetapageMigratedDialog5.push(this.$MetapageMigratedDialog2.subscribe('mouseenter',(function(l,m){this.$MetapageMigratedDialog6();return false;}).bind(this)));this.$MetapageMigratedDialog5.push(this.$MetapageMigratedDialog2.subscribe('mouseleave',(function(l,m){this.$MetapageMigratedDialog7();return false;}).bind(this)));this.$MetapageMigratedDialog5.push(this.$MetapageMigratedDialog2.subscribe('success',(function(l,m){this.$MetapageMigratedDialog8();return false;}).bind(this)));this.$MetapageMigratedDialog2.subscribe('button',(function(l,m){this.$MetapageMigratedDialog3.show();return true;}).bind(this));h.listen(this.$MetapageMigratedDialog1,'click',(function(l){this.$MetapageMigratedDialog2.show();}).bind(this));return this;};k.prototype.$MetapageMigratedDialog7=function(){"use strict";if(this.$MetapageMigratedDialog2.isShown()&&!this.$MetapageMigratedDialog9)this.$MetapageMigratedDialog9=setTimeout((function(){this.$MetapageMigratedDialog9=null;this.$MetapageMigratedDialog2.hide();}).bind(this),1000);};k.prototype.$MetapageMigratedDialog6=function(){"use strict";if(this.$MetapageMigratedDialog9){clearTimeout(this.$MetapageMigratedDialog9);this.$MetapageMigratedDialog9=null;}};k.prototype.$MetapageMigratedDialog8=function(){"use strict";this.$MetapageMigratedDialog4.forEach(function(l){l.remove();});this.$MetapageMigratedDialog5.forEach((function(l){this.$MetapageMigratedDialog2.unsubscribe(l);}).bind(this));};e.exports=k;},null);
__d("OptionButtonSetController",["Button","CSS","cx","DOMEventListener","DataStore","Event","Input","KnowledgeClaimSentimentEnum","Parent","copyProperties"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p){b.__markCompiled&&b.__markCompiled();function q(r,s,t,u){this._valueInput=t;this._buttons=s;this._preventToggle=u;this._voteRow=o.byClass(r,"_226w");for(var v=0;v<s.length;v++)j.add(s[v],'click',function(w){this._toggleButtonFromNode(o.byTag(w.getTarget(),'button'));w.kill();}.bind(this));k.set(r,'OptionButtonSetController',this);}p(q.prototype,{toggleButton:function(r){this._toggleButtonFromNode(this._buttons[r]);},getButton:function(r){return this._buttons[r];},_toggleButtonFromNode:function(r){var s=!g.isDepressed(r);if(!s&&this._preventToggle)return;g.setDepressed(r,s);m.setValue(this._valueInput,s?r.value:null);this._updateCurrentSentiment(s?r.value:null);l.fire(this._valueInput,'input');for(var t=0;t<this._buttons.length;t++)if(this._buttons[t]!=r)g.setDepressed(this._buttons[t],false);},_updateCurrentSentiment:function(r){if(!this._voteRow)return;switch(r){case n.AGREE:h.addClass(this._voteRow,"__wp");h.removeClass(this._voteRow,"__x4");break;case n.DISAGREE:h.removeClass(this._voteRow,"__wp");h.addClass(this._voteRow,"__x4");break;default:h.removeClass(this._voteRow,"__wp");h.removeClass(this._voteRow,"__x4");break;}}});e.exports=q;},null);
__d("PageRedirectDialogController",["AsyncRequest"],function(a,b,c,d,e,f,g){b.__markCompiled&&b.__markCompiled();var h={init:function(i,j){this._dialog=i;this._uri=j;i.subscribe('cancel',this._formCancel.bind(this));},_formCancel:function(i,event){this._dialog.hide();new g(this._uri).setMethod('POST').send();}};e.exports=h;},null);