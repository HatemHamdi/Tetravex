/*!CK:66919457!*//*1428305243,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["LguNw"]); }

__d("BookmarkPopoverMenu.react",["Arbiter","Link.react","MenuSeparator.react","PopoverMenu.react","React","ReactXUIMenu","cx","fbt"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n){b.__markCompiled&&b.__markCompiled();'use strict';var o=l.Item,p=k.createClass({displayName:"BookmarkPopoverMenu",render:function(){var q=this._renderMenuContent();if(q.length===0)return null;var r=k.createElement(l,null,q),s=n._("Modifier"),t=(k.createElement(h,{href:"#",title:s,"aria-label":s,onClick:this.props.loadPopupModules,className:"_1wc5 _26tg accessible_elem"}));return (k.createElement("div",{className:"buttonWrap"},k.createElement(j,{ref:"popovermenu",className:"uiSideNavEditButton",menu:r},t)));},_renderMenuContent:function(){var q=this.props.navItem,r=this.props.navSection,s=this.props.editmenu,t=q.props.model.pinned,u=r.props.id==='pinnedNav',v=[];if(s.favoriteOption){var w=t?s.favoriteOption.title.unfavorite:s.favoriteOption.title.favorite;v.push(k.createElement(o,{onclick:this._toggleFavorite,key:"menu_favorite"},w));}if(u&&s.rearrangeOption)v.push(k.createElement(o,{onclick:this._toggleEditMode,key:"menu_edit"},s.rearrangeOption.title));if(s.hideOption)v.push(this._renderAjaxMenuItem(s.hideOption,'menu_hide_option'));if(s.editOption)v.push(this._renderAjaxMenuItem(s.editOption,'menu_edit_option'));if(s.deleteOption){if(v.length!==0)v.push(k.createElement(i,{key:"menu_sep"}));v.push(this._renderAjaxMenuItem(s.deleteOption,'menu_delete_option'));}return v;},_renderAjaxMenuItem:function(q,r){return (k.createElement(o,{href:q.href,ajaxify:q.ajaxify,rel:q.rel,key:r},q.title));},_toggleFavorite:function(){var q=this.props.navItem;g.inform('LeftNavController/toggleFavorite',q.props.model.id);},_toggleEditMode:function(){g.inform('LeftNavDragController/toggleEditMode',{section:this.props.navSection});}});e.exports=p;},null);