/*!CK:3919622757!*//*1427685969,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["IhKCr"]); }

__d("StickyController",["CSS","Event","Style","Vector","queryThenMutateDOM"],function(a,b,c,d,e,f,g,h,i,j,k){b.__markCompiled&&b.__markCompiled();function l(m,n,o,p){"use strict";this._element=m;this._marginTop=n;this._onchange=o;this._proxy=p||m.parentNode;this._boundQueryOnScroll=this.shouldFix.bind(this);this._boundMutateOnScroll=this._mutateOnScroll.bind(this);}l.prototype.handleScroll=function(){"use strict";k(this._boundQueryOnScroll,this._boundMutateOnScroll);};l.prototype.shouldFix=function(){"use strict";return j.getElementPosition(this._proxy,'viewport').y<=this._marginTop;};l.prototype._mutateOnScroll=function(){"use strict";var m=this.shouldFix();if(this.isFixed()!==m){i.set(this._element,'top',m?this._marginTop+'px':'');g.conditionClass(this._element,'fixed_elem',m);this._onchange&&this._onchange(m);}};l.prototype.start=function(){"use strict";if(this._event)return;this._event=h.listen(window,'scroll',this.handleScroll.bind(this));setTimeout(this.handleScroll.bind(this),0);};l.prototype.stop=function(){"use strict";this._event&&this._event.remove();this._event=null;};l.prototype.isFixed=function(){"use strict";return g.hasClass(this._element,'fixed_elem');};e.exports=l;},null);
__d("TimelineSideAds",["AdsMouseStateStore","Animation","Arbiter","CSS","DOM","EgoAdsObjectSet","Event","ProfileTabUtils","StickyController","TimelineAdsConfig","TimelineComponentKeys","TimelineConstants","TimelineController","UIPagelet","URI","Vector","csx","cx","debounce","ge"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z){b.__markCompiled&&b.__markCompiled();var aa=75,ba='data-height',ca=g.STATES,da=30000,ea=0,fa=false,ga,ha,ia,ja,ka,la,ma=new l(),na,oa,pa=false,qa,ra=Infinity,sa=false,ta=5,ua,va,wa,xa,ya,za,ab,bb,cb,db,eb,fb,gb,hb=false,ib=[],jb;function kb(jc,kc,lc){var mc=0;if(kc)mc+=kc.getHeight();if(!pb()&&!mc)return;jc-=mc;var nc=0;for(var oc=0;oc<lc;oc++)nc+=yb(oc);if(kc)if(jc<nc){jc+=kc.fold(nc-jc);}else if(jc>nc)jc-=kc.unfold(jc-nc);return jc;}function lb(){var jc=ha.cloneNode(true);jc.id='';var kc=new l();kc.init(k.scry(jc,'div.ego_unit'));var lc=true;kc.forEach(function(mc){if(lc){lc=false;}else k.remove(mc);});j.addClass(jc,'fixed_elem');return jc;}function mb(){la=(void 0);if(!n.tabHasScrubber(na)){qb(ta);tb();}else if(za){rb(ha,false);var jc=ab;ab&&k.remove(ab);ab=lb();if(jc)ec();qb(s.sidebarInitialized()&&pa?xa:wa);tb();if(!qa){var kc=s.getCurrentScrubber();if(kc)dc(kc.getRoot(),kc.getOffset());}qa&&qa.start();}else ic.adjustAdsToFit();}function nb(){if(ab){k.remove(ab);ab=null;}if(qa){qa.stop();qa=null;}var jc=n.tabHasScrubber(na);j.conditionClass(ha,'fixed_elem',!za&&(pb()||jc));j.conditionClass(ha,"_31wm",!jc);j.conditionClass(ha,"_5r9k",jc);}function ob(jc){var kc=v.getViewportDimensions().y,lc=s.getCurrentScrubber(),mc=lc?lc.getOffset():r.SCRUBBER_DEFAULT_OFFSET,nc=kc-mc-aa;if(lc||pb())return kb(nc,lc,jc);}function pb(){return n.tabHasFixedAds(na);}function qb(jc){ka=Math.min(jc,ma.getCount());ma.forEach(function(kc,lc){rb(kc,lc>=ka);});rb(ha,ka===0);}function rb(jc,kc){j.conditionClass(jc,"_22r",kc);jc.setAttribute('aria-hidden',kc?'true':'false');}function sb(jc){var kc=k.find(ma.getUnit(jc),"div._4u8"),lc=kc.getAttribute('data-ad');return JSON.parse(lc).adid;}function tb(){vb();ub();}function ub(){var jc;if(la!==(void 0)){jc=ma.getHoldoutAdIDsForSpace(la,zb);}else jc=ma.getHoldoutAdIDsForNumAds(ka);if(jc)jc.forEach(wb);}function vb(){if(!bb)return;for(var jc=ka-1;jc>=0;--jc){if(qa&&qa.isFixed()&&((jc!==0)||(ab&&!j.shown(ab))))continue;var kc=sb(jc);if(!bb[kc])return;wb(kc);}}function wb(jc){if(!bb[jc])return;var kc=k.create('iframe',{src:u('/ai.php').addQueryData({aed:bb[jc]}),width:0,height:0,frameborder:0,scrolling:'no',className:'fbEmuTracking'});kc.setAttribute('aria-hidden','true');k.appendContent(ha,kc);delete bb[jc];}function xb(jc){var kc=0;while(jc>0&&kc<ta){jc-=yb(kc);if(jc>=0)kc++;}return kc;}function yb(jc){var kc=ma.getUnit(jc);if(!kc)return 0;return zb(kc);}function zb(jc){if(!jc.getAttribute(ba))ac(jc);return parseInt(jc.getAttribute(ba),10);}function ac(jc){jc.setAttribute(ba,jc.offsetHeight);}function bc(){for(var jc=0;jc<ma.getCount();jc++){var kc=ma.getUnit(jc);if(!kc)continue;ac(kc);}}function cc(){var jc=k.scry(ha,'div.ego_unit');ma.init(jc);var kc=jc.length;if(!kc)return;j.addClass(ma.getUnit(0),'ego_unit_no_top_border');mb();setTimeout(function(){jc.forEach(ac);ic.adjustAdsToFit();ra=Date.now();},0);}function dc(jc,kc){qa=new o(jc,kc,function(lc){if(lc){ec();}else{k.remove(ab);tb();}});if(ab)qa.start();}function ec(){k.insertAfter(ha,ab);fc();}function fc(){j.conditionShow(ab,yb(0)<=ob(1)&&!j.hasClass(document.documentElement,'tinyViewport'));}function gc(){if(oa){var jc=z(ia);k.find(jc,'.ego_column').appendChild(oa);}if(p.fade)(new h(z(ia))).from('opacity',0).to('opacity',1).duration(600).go();}function hc(jc){return !!k.scry(jc,'div.fbEmuHidePoll')[0];}var ic={init:function(jc,kc,lc){if(fa)return;ta=lc.max_ads;ga=lc.refresh_delay;da=lc.refresh_threshold;ua=lc.min_ads;va=lc.min_ads_wide;wa=lc.min_ads_short;xa=lc.min_ads_short_wide;fa=true;ja=kc;ha=jc;g.updateRhcID(k.getID(ha));ic.adjustAdsType(s.shouldShowWideAds());cb=i.subscribe(['UFI/CommentAddedActive','UFI/CommentDeletedActive','UFI/LikeActive','Curation/Action','ProfileBrowser/LoadMoreContent','Ads/NewContentDisplayed'],ic.loadAdsIfEnoughTimePassed);db=i.subscribe('TimelineSideAds/refresh',ic.forceReloadAds);eb=i.subscribe('ProfileQuestionAnswered',ic.forceReloadAdsWithCallback);fb=i.subscribe('Ads/displayPoll',ic.displayAdsPoll);gb=i.subscribe('Ads/hidePoll',ic.hideAdsPoll);jb=y(ic.loadAdsIfEnoughTimePassed,ga,this,true);if(lc.mouse_move){ib.push(m.listen(window,'mousemove',jb));ib.push(m.listen(window,'scroll',jb));ib.push(m.listen(window,'resize',jb));ib.push(m.listen(ha,'mouseenter',function(){sa=true;}));ib.push(m.listen(ha,'mouseleave',function(){sa=false;}));}s.register(q.ADS,ic);},setShortMode:function(jc){za=jc;},start:function(jc){bb=jc;ya=null;cc();},updateCurrentKey:function(jc){if(jc==na)return;na=jc;nb();},loadAds:function(jc){if(ya)return;ra=Infinity;ya=t.loadFromEndpoint('WebEgoPane',ha.id,{pid:33,data:[ja,'timeline_'+jc,za?xa:ta,++ea,false]},{crossPage:true,bundle:false,handler:gc});},registerScrubber:function(jc){if(za)dc(jc.getRoot(),jc.getOffset());!ya&&ic.adjustAdsToFit();},intentShown:function(){if(!p.stateRefresh)return false;switch(g.getState()){case ca.HOVER:case ca.INTENT:default:return true;case ca.NO_INTENT:return false;case ca.STATIONARY:return !p.refreshOnStationary;}},loadAdsIfEnoughTimePassed:function(){if(da&&(Date.now()-ra>=da)&&!j.hasClass(document.documentElement,'tinyViewport')&&(!qa||qa.isFixed())&&(!bb||!bb[sb(0)])&&!ic.intentShown()&&!sa)ic.loadAds(na);ic.adjustAdsToFit();},forceReloadAdsWithCallback:function(jc,kc){oa=kc;ia=k.getID(ha);ic.loadAds(na);},forceReloadAds:function(){ic.loadAds(na);},adjustAdsType:function(jc){if(jc!=pa){j.conditionClass(ha,"_22q",!jc);j.conditionClass(ha,"_35q",!jc);ab&&j.conditionClass(ab,"_22q",!jc);ab&&j.conditionClass(ab,"_35q",!jc);pa=jc;bc();ic.adjustAdsToFit();var kc=z('rightColContent');if(kc)j.conditionClass(kc,'fbTimelineWideRightCol',jc);}},displayAdsPoll:function(){var jc=-1;for(var kc=0;kc<ma.getCount();kc++){var lc=ma.getUnit(kc);if(!lc)continue;if(jc===-1&&hc(lc))jc=kc;ac(lc);}ic.adjustAdsToFit();if(jc===ka&&jc>0){rb(ma.getUnit(jc-1),true);rb(ma.getUnit(jc),false);}},hideAdsPoll:function(){bc();ic.adjustAdsToFit();},adjustAdsToFit:function(){if(!ha||hb)return;hb=true;var jc;if(za){jc=pa?xa:wa;if(qa&&ab){qa.handleScroll();if(qa.isFixed()){j.conditionShow(ab,yb(0)<=ob(1)&&!j.hasClass(document.documentElement,'tinyViewport'));}else qb(jc);tb();}}else{jc=pa?va:ua;var kc=ob(jc);if(typeof kc!=='undefined'){la=kc;qb(xb(kc));tb();}}hb=false;},reset:function(){qa&&qa.stop();ya&&ya.cancel();ma=new l();pa=false;ha=null;qa=null;ya=null;ea=0;za=null;ab=null;na=null;ra=Infinity;fa=false;cb&&i.unsubscribe(cb);cb=null;db&&i.unsubscribe(db);db=null;eb&&i.unsubscribe(eb);fb&&i.unsubscribe(fb);gb&&i.unsubscribe(gb);eb=null;sa=false;ib.forEach(function(jc){jc.remove();});ib=[];jb&&jb.reset();}};e.exports=a.TimelineSideAds||ic;},null);
__d("TimelineStickyHeader",["Animation","Arbiter","Bootloader","CSS","DOM","ProfileTabConst","ProfileTabUtils","Style","TimelineComponentKeys","TimelineController","Vector","ViewportBounds","csx","ge","queryThenMutateDOM"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u){b.__markCompiled&&b.__markCompiled();var v=200,w=false,x=false,y,z,aa,ba,ca,da,ea={},fa={VISIBLE:'TimelineStickyHeader/visible',ADJUST_WIDTH:'TimelineStickyHeader/adjustWidth',init:function(ga){if(w)return;w=true;y=ga;z=k.find(ga,'div.name');aa=k.find(ga,'div.actions');x=j.hasClass(ga,'fbTimelineStickyHeaderVisible');var ha=k.find(document,"div._4f7n"),ia,ja=false;u(function(){if(ha.offsetTop&&!t('page_admin_panel')&&p.getCurrentKey()!==l.TIMELINE){ia=q.tElementDimensions(ha).y;ja=true;}},function(){if(ja){i.loadModules(["StickyController"],function(ka){new ka(ga,ia).start();});}else j.addClass(ga,'fixed_elem');u(function(){ca=ga.offsetTop;da=ga.scrollHeight;},function(){ba=r.addTop(function(){return x?ca+da:0;});},'TimelineStickyHeader/init');p.register(o.STICKY_HEADER,fa);},'TimelineStickyHeader/init');},reset:function(){w=false;x=false;y=null;z=null;aa=null;ea={};ba.remove();ba=null;},handleTabChange:function(ga){if(!m.tabHasStickyHeader(ga)){this.toggle(false,function(){return j.hide(y);});return;}j.show(y);},toggle:function(ga,ha){if(ga===x){ha&&ha();return;}var ia=ga?ca-da:ca,ja=ga?ca:ca-da;n.set(y,'top',ia+'px');j.addClass(y,'fbTimelineStickyHeaderAnimating');var ka=k.getID(y);ea[ka]&&ea[ka].stop();ea[ka]=new g(y).from('top',ia).to('top',ja).duration(v).ondone(function(){ea[ka]=null;j.conditionClass(y,'fbTimelineStickyHeaderHidden',!ga);y.setAttribute('aria-hidden',ga?'false':'true');j.removeClass(y,'fbTimelineStickyHeaderAnimating');n.set(y,'top','');h.inform(fa.VISIBLE,ga);ha&&ha();}).go();x=ga;if(x)fa.adjustWidth();},adjustWidth:function(){h.inform(fa.ADJUST_WIDTH,z,h.BEHAVIOR_STATE);},getRoot:function(){return y;},setActions:function(ga){if(w&&ga){k.setContent(aa,ga);aa=ga;}}};e.exports=a.TimelineStickyHeader||fa;},null);
__d("ButtonGroup",["CSS","DataStore","Parent","copyProperties","createArrayFromMixed"],function(a,b,c,d,e,f,g,h,i,j,k){b.__markCompiled&&b.__markCompiled();var l='firstItem',m='lastItem';function n(s,t){var u=i.byClass(s,t);if(!u)throw new Error('invalid use case');return u;}function o(s){return g.shown(s)&&k(s.childNodes).some(g.shown);}function p(s){var t,u,v;k(s.childNodes).forEach(function(w){v=o(w);g.removeClass(w,l);g.removeClass(w,m);g.conditionShow(w,v);if(v){t=t||w;u=w;}});t&&g.addClass(t,l);u&&g.addClass(u,m);g.conditionShow(s,t);}function q(s,t){var u=n(t,'uiButtonGroupItem');s(u);p(u.parentNode);}function r(s){"use strict";this._root=n(s,'uiButtonGroup');h.set(this._root,'ButtonGroup',this);p(this._root);}r.getInstance=function(s){"use strict";var t=n(s,'uiButtonGroup'),u=h.get(t,'ButtonGroup');return u||new r(t);};j(r.prototype,{hideItem:q.bind(null,g.hide),showItem:q.bind(null,g.show),toggleItem:q.bind(null,g.toggle)});e.exports=r;},null);
__d("TimelineStickyHeaderNav",["Arbiter","ButtonGroup","CSS","DataStore","DOM","Event","Parent","SelectorDeprecated","Style","SubscriptionsHandler","TimelineComponentKeys","TimelineConstants","TimelineController","TimelineLegacySections","URI","Vector","csx","fbt"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x){b.__markCompiled&&b.__markCompiled();var y=false,z,aa,ba,ca,da,ea,fa,ga,ha,ia,ja,ka={},la={},ma=[],na=false,oa=[],pa=[],qa,ra=[x._("janvier"),x._("f\u00e9vrier"),x._("mars"),x._("avril"),x._("mai"),x._("juin"),x._("juillet"),x._("ao\u00fbt"),x._("septembre"),x._("octobre"),x._("novembre"),x._("d\u00e9cembre")];function sa(){var fb=n.getSelectorMenu(da);qa.addSubscriptions(l.listen(fb,'click',ta),g.subscribe(r.SECTION_REGISTERED,xa));}function ta(event){var fb=m.byTag(event.getTarget(),'a'),gb=fb&&j.get(fb,'key');if(gb){s.stickyHeaderNavWasClicked(gb);s.navigateToSection(gb);event.prevent();}}function ua(fb,gb){var hb=n.getValue(gb);if(hb==='allStories')t.get(fb).expandSubSections();if(hb!=='activityLog')va(gb);}function va(fb){db(fb,'highlights');db(fb,'allStories');var gb=k.find(fb,'li.separator');i.conditionShow(gb,gb.previousSibling);}function wa(fb){if(ia===fb&&ga[fb]&&!aa.custom_subsection_menu){bb(fb);}else ya();s.adjustStickyHeaderWidth();}function xa(fb,gb){var hb=gb.period,ib=hb.parentKey;if(!ib)return;var jb=ab(ib),kb=s.getCurrentScrubber(),lb=hb.scrubberKey,mb=kb?kb.getLabelForSubnav(ib,lb):mb=za(lb);if(mb){ga[ib]=true;cb(jb,{key:lb,label:mb});wa(ib);}}function ya(){ba.hideItem(ea);}function za(fb){var gb=fb.split('_');return ra[gb.pop()-1];}function ab(fb){var gb=fa[fb];if(!gb){gb=fa[fb]=ea.cloneNode(true);var hb=k.scry(gb,'li.activityLog a')[0];if(hb)hb.href=u(hb.href).addQueryData({key:fb});qa.addSubscriptions(n.listen(gb,'change',ua.bind(null,fb,gb)),l.listen(gb,'click',ta));}return gb;}function bb(fb){var gb=ab(fb);k.insertAfter(ea,gb);i.hide(ea);for(var hb in fa){var ib=fa[hb];i.conditionShow(ib,ib===gb);}ba.showItem(ea);}function cb(fb,gb){var hb=k.create('a',{href:'#',rel:'ignore',className:'itemAnchor',tabIndex:0},k.create('span',{className:'itemLabel fsm'},gb.label));hb.setAttribute('data-key',gb.key);hb.setAttribute('aria-checked',false);var ib=k.create('li',{className:'uiMenuItem uiMenuItemRadio uiSelectorOption'},hb);ib.setAttribute('data-label',gb.label);var jb=k.find(fb,'ul.uiMenuInner'),kb=k.create('option',{value:gb.key},gb.label),lb=k.find(fb,'select');if(gb.key==='recent'){k.prependContent(jb,ib);k.insertAfter(lb.options[0],kb);}else{k.appendContent(jb,ib);k.appendContent(lb,kb);}}function db(fb,gb){var hb=k.scry(fb,'li.uiMenuItem');if(!hb)return;for(var ib=0;ib<hb.length;ib++){var jb=hb[ib];if(i.hasClass(jb,gb)||jb.firstChild.getAttribute('data-key')==gb){k.remove(jb);break;}}var kb=k.find(fb,'select'),lb=k.scry(kb,'option');for(ib=0;ib<lb.length;ib++)if(lb[ib].value===gb){k.remove(lb[ib]);return;}}var eb={init:function(fb,gb){if(y)return;y=true;z=fb;aa=gb||{};ca=k.find(z,'div.pageMenu');da=k.find(z,'div.sectionMenu');ea=k.find(z,'div.subsectionMenu');ja=k.find(ca,'li.uiMenuSeparator');ba=h.getInstance(ca);qa=new p();fa={};ga={};ha={};eb.adjustMenuHeights();sa();s.register(q.STICKY_HEADER_NAV,eb);pa.forEach(function(hb){hb();});},reset:function(){y=false;aa={};ma=[];ka={};la={};na=false;oa=[];z=null;ca=null;da=null;ea=null;ja=null;fa={};ga={};ha={};qa.release();},addTimePeriod:function(fb){var gb=s.getCurrentScrubber();if(!gb)return;var hb=gb.getLabelForNav(fb);if(!hb)return;cb(da,{key:fb,label:hb});var ib=k.find(da,'ul.uiMenuInner');if(fb==='recent'||ib.children.length<2)n.setSelected(da,fb,true);},updateSection:function(fb,gb){if(gb){var hb=ab(fb);n.setSelected(hb,gb);va(hb);}else ha[fb]=true;ia=fb;n.setSelected(da,fb,true);wa(fb);},adjustMenuHeights:function(){[ca,da].forEach(function(fb){var gb='';if(!i.hasClass(document.documentElement,'tinyViewport')){gb=v.getViewportDimensions().y-v.getElementDimensions(k.scry(document,"div._4f7n")[0]).y-80;gb+='px';}o.set(k.find(fb,'ul.uiMenuInner'),'maxHeight',gb);});},initPageMenu:function(fb,gb){if(!y){pa.push(eb.initPageMenu.bind(null,fb,gb));return;}function hb(ib,jb){ib.forEach(function(kb){var lb=la[kb]=k.create('li');i.hide(lb);jb?k.insertBefore(ja,lb):k.appendContent(k.find(ca,'ul.uiMenuInner'),lb);});}hb(fb,true);hb(gb,false);ka.info=k.scry(ca,'li')[0];ma=gb;na=true;if(oa.length)oa.forEach(function(ib){eb.registerPageMenuItem(ib.key,ib.item);});},registerPageMenuItem:function(fb,gb){if(!na){oa.push({key:fb,item:gb});return;}if(la[fb]){k.replace(la[fb],gb);ka[fb]=gb;delete la[fb];if(ma.indexOf(fb)>=0)i.show(ja);}},removeTimePeriod:function(fb){db(da,fb);},hideSectionMenu:function(){y&&i.hide(da);}};e.exports=eb;},null);
__d("TimelineScrubber",["CSS","DOM","Event","Focus","Keys","Parent","ProfileTabUtils","TimelineComponentKeys","TimelineController","Vector","copyProperties","cx","getElementText"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s){b.__markCompiled&&b.__markCompiled();var t="_3rrn";function u(v){"use strict";this.$TimelineScrubber0=v;this.$TimelineScrubber1={};this.$TimelineScrubber2={};this.$TimelineScrubber3={};this.$TimelineScrubber4={};var w=v.childNodes;this.$TimelineScrubber5=w[0];for(var x=0;x<w.length;x++){var y=w[x].getAttribute('data-key');this.$TimelineScrubber1[y]=w[x];var z=h.scry(w[x],'ul');this.$TimelineScrubber2[y]={};if(z.length){var aa=z[0].childNodes;for(var ba=0;ba<aa.length;ba++)this.$TimelineScrubber2[y][aa[ba].getAttribute('data-key')]=aa[ba];}var ca=w[x].getAttribute('data-rollup');if(ca){this.$TimelineScrubber3[ca]=this.$TimelineScrubber3[ca]||[];this.$TimelineScrubber3[ca].push(w[x]);}}this.$TimelineScrubber6=i.listen(this.$TimelineScrubber0,'click',this.$TimelineScrubber7.bind(this));this.$TimelineScrubber8=i.listen(this.$TimelineScrubber0,'keydown',this.$TimelineScrubber9.bind(this));this.$TimelineScrubbera=h.scry(this.$TimelineScrubber0,'a')[0];g.show(this.$TimelineScrubber0);var da=p.getViewportDimensions().y-this.SCRUBBER_NO_ADS_VERTICAL_BUFFER,ea=this.getHeight();if(ea>da)this.fold(ea-da);o.register(n.SCRUBBER,this);o.scrubberHasLoaded(this);}u.prototype.reset=function(){"use strict";this.$TimelineScrubber6&&this.$TimelineScrubber6.remove();this.$TimelineScrubber8&&this.$TimelineScrubber8.remove();this.$TimelineScrubber0=null;this.$TimelineScrubber1={};this.$TimelineScrubber2={};this.$TimelineScrubber3={};this.$TimelineScrubber4={};};u.prototype.getRoot=function(){"use strict";return this.$TimelineScrubber0;};u.prototype.getNav=function(v){"use strict";return this.$TimelineScrubber1[v];};u.prototype.getSubnav=function(v,w){"use strict";var x=this.$TimelineScrubber2[v];return x&&x[w];};u.prototype.getHeight=function(){"use strict";return this.$TimelineScrubber0.offsetHeight;};u.prototype.getLabelForNav=function(v){"use strict";var w=this.getNav(v);return w&&s(h.scry(w,'a')[0]);};u.prototype.getLabelForSubnav=function(v,w){"use strict";var x=this.getSubnav(v,w);return x&&s(h.scry(x,'a')[0]);};u.prototype.fold=function(v){"use strict";return this.$TimelineScrubberb(v,true);};u.prototype.unfold=function(v){"use strict";return this.$TimelineScrubberb(v,false);};u.prototype.handleTabChange=function(v){"use strict";g.conditionShow(this.$TimelineScrubber0,m.tabHasScrubber(v));};u.prototype.getOffset=function(){"use strict";return this.OFFSET+(g.hasClass(document.body,'hasVoiceBar')?26:0)+(g.hasClass('rightColContent','pagesTimelineRightColumn')?48:0);};u.prototype.updateSection=function(v,w){"use strict";if(!this.$TimelineScrubber1[v])return;var x=this.$TimelineScrubber1[v].getAttribute('data-rollup');if(this.$TimelineScrubberc&&this.$TimelineScrubberc!=x){g.removeClass(this.$TimelineScrubberc,t);g.removeClass(h.scry(this.$TimelineScrubberc,'ul')[0],'loaded');delete this.$TimelineScrubberc;}if(x&&this.$TimelineScrubber4[x]){var y=this.$TimelineScrubber4[x];if(y.getAttribute('data-rollup')){this.$TimelineScrubberc=y;g.addClass(this.$TimelineScrubberc,t);g.addClass(h.scry(this.$TimelineScrubberc,'ul')[0],'loaded');}}this.$TimelineScrubber5&&g.removeClass(this.$TimelineScrubber5,t);this.$TimelineScrubberd&&g.removeClass(this.$TimelineScrubberd,t);this.$TimelineScrubber5=null;this.$TimelineScrubberd=null;if(this.$TimelineScrubber1[v]){this.$TimelineScrubber5=this.$TimelineScrubber1[v];g.addClass(this.$TimelineScrubber5,t);if(this.decadesAreSelectable&&this.$TimelineScrubber1[w]){this.$TimelineScrubberd=this.$TimelineScrubber1[w];g.addClass(this.$TimelineScrubberd,t);}else if(w&&this.$TimelineScrubber2[v][w]){this.$TimelineScrubberd=this.$TimelineScrubber2[v][w];g.addClass(this.$TimelineScrubberd,t);}}};u.prototype.$TimelineScrubbere=function(v){"use strict";var w=this.$TimelineScrubber5,x=w&&w.getAttribute('data-rollup'),y=this.KEY_HEIGHT*(this.$TimelineScrubber3[v].length-1);if(v==x){y+=this.SUBKEY_HEIGHT*h.scry(w,'li').length;y-=this.SUBKEY_HEIGHT*(this.$TimelineScrubber3[v].length-1);}return y;};u.prototype.$TimelineScrubberb=function(v,w){"use strict";var x=v,y=Object.keys(this.$TimelineScrubber3);while(v>0&&y.length){var z=y[w?'pop':'shift']();if(!w==!this.$TimelineScrubber4[z])continue;var aa=this.$TimelineScrubbere(z);if(aa<=0)continue;if(!w&&aa>v)break;if(w){this.$TimelineScrubberf(z);}else this.$TimelineScrubberg(z);v-=aa;}return x-v;};u.prototype.$TimelineScrubberf=function(v){"use strict";var w=this.$TimelineScrubber3[v];if(!w||w.length<2||this.$TimelineScrubber4[v])return;var x=w[0].previousSibling,y=w[0],z=h.create('a',{href:y.firstChild.href,rel:'ignore',tabindex:'-1'},[v]),aa=h.create('ul',{className:'clearfix'});for(var ba=0;ba<w.length;ba++)aa.appendChild(w[ba]);var ca=h.create('li',null,[z,aa]);if(this.decadesAreSelectable){var da=w[w.length-1],ea=y.getAttribute('data-key')+da.getAttribute('data-key');ca.setAttribute('data-start',da.getAttribute('data-start'));ca.setAttribute('data-end',y.getAttribute('data-end'));ca.setAttribute('data-key',ea);this.$TimelineScrubber1[ea]=ca;}else ca.setAttribute('data-key',y.getAttribute('data-key'));ca.setAttribute('data-rollup',v);if(x){h.insertAfter(x,ca);}else h.prependContent(this.$TimelineScrubber0,ca);this.$TimelineScrubber4[v]=ca;this.$TimelineScrubberh();this.$TimelineScrubberi();};u.prototype.$TimelineScrubberg=function(v){"use strict";if(!this.$TimelineScrubber4[v])return;var w=this.$TimelineScrubber4[v],x=h.scry(w,'ul')[0],y=document.createDocumentFragment();while(x.childNodes.length)y.appendChild(x.firstChild);h.replace(w,y);this.$TimelineScrubber4[v]=false;this.$TimelineScrubberh();};u.prototype.$TimelineScrubberh=function(){"use strict";if(this.$TimelineScrubber5){var v=this.$TimelineScrubberd&&this.$TimelineScrubberd.getAttribute('data-key');this.updateSection(this.$TimelineScrubber5.getAttribute('data-key'),v);}};u.prototype.$TimelineScrubber7=function(event){"use strict";var v=event.getModifiers();if(event.isMiddleClick()||v.access||v.meta)return true;var w=l.byTag(event.getTarget(),'a'),x=w&&l.byAttribute(w,'data-key');if(x){o.scrubberWasClicked(x.getAttribute('data-key'));o.navigateToSection(x.getAttribute('data-key'));return event.prevent();}};u.prototype.$TimelineScrubberi=function(){"use strict";while(!(this.$TimelineScrubbera.offsetHeight||this.$TimelineScrubbera.offsetWidth)){this.$TimelineScrubbera.tabIndex=-1;var v=l.byTag(l.byTag(this.$TimelineScrubbera,'li'),'li'),w=h.scry(v,'a')[0];if(w===this.$TimelineScrubbera)return;this.$TimelineScrubbera=w;this.$TimelineScrubbera.tabIndex=0;}};u.prototype.$TimelineScrubber9=function(event){"use strict";if(event.getModifiers().any)return;var v=i.getKeyCode(event);if(v===k.UP||v===k.DOWN){var w=h.scry(this.$TimelineScrubber0,'a').filter(function(z){return z.offsetHeight||z.offsetWidth;}),x=w.indexOf(this.$TimelineScrubbera);if(x!=-1){var y=w[x+(v===k.UP?-1:1)];if(y){y.tabindex=0;j.set(y);this.$TimelineScrubbera.tabindex=-1;this.$TimelineScrubbera=y;event.prevent();}}}};q(u.prototype,{KEY_HEIGHT:23,SUBKEY_HEIGHT:16,OFFSET:38,SCRUBBER_NO_ADS_VERTICAL_BUFFER:125});e.exports=u;},null);
__d("TimelineMainScrubber",["Arbiter","CSS","DOMQuery","TimelineConstants","TimelineController","TimelineScrubber"],function(a,b,c,d,e,f,g,h,i,j,k,l){b.__markCompiled&&b.__markCompiled();for(var m in l)if(l.hasOwnProperty(m))o[m]=l[m];var n=l===null?null:l.prototype;o.prototype=Object.create(n);o.prototype.constructor=o;o.__superConstructor__=l;function o(p){"use strict";l.call(this,p);this.$TimelineMainScrubber0=g.subscribe(j.SECTION_LOADED,function(q,r){var s=this.getNav(r.key),t=s&&i.scry(s,'ul')[0];if(t){h.addClass(t,'loaded');k.scrubberHasChangedState();if(r.hideSubSections)h.hide(t);}}.bind(this));}o.prototype.reset=function(){"use strict";n.reset.call(this);this.$TimelineMainScrubber0&&this.$TimelineMainScrubber0.unsubscribe();};e.exports=o;},null);
__d("ButtonGroupMonitor",["ContextualDialog","ContextualLayer","CSS","Layer","Parent","SelectorDeprecated","DataStore"],function(a,b,c,d,e,f,g,h,i,j,k,l,m){b.__markCompiled&&b.__markCompiled();function n(o,p){var q=k.byClass(o,'bg_stat_elem')||k.byClass(o,'uiButtonGroup');if(!q&&p)q=m.get(p,'toggleElement',null);if(q){p&&m.set(p,'toggleElement',q);i.toggleClass(q,'uiButtonGroupActive');}}j.subscribe(['hide','show'],function(o,p){if(p instanceof h||p instanceof g)n(p.getCausalElement(),p);});l.subscribe(['close','open'],function(o,p){n(p.selector);});},null);