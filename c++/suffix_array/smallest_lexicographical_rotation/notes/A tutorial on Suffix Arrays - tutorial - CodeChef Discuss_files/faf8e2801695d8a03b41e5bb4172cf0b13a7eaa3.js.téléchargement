(function() {
  if ('Discourse' in window) {
    Discourse.RAW_TEMPLATES["mobile/list/topic-list-item"] = requirejs('discourse-common/lib/raw-handlebars').template({"1":function(container,depth0,helpers,partials,data) {
    return "  <div class='pull-left'>\n    <a href=\""
    + container.escapeExpression(helpers.get.call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.lastPostUrl",{"name":"get","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\" class=\"mobile-homepage-avatar "
    + container.escapeExpression(helpers.get.call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.lastPoster.extraClasses",{"name":"get","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\">"
    + container.escapeExpression((helpers.avatar || (depth0 && depth0.avatar) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.lastPoster",{"name":"avatar","hash":{"imageSize":"large"},"hashTypes":{"imageSize":"StringLiteral"},"hashContexts":{"imageSize":depth0},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "</a>\n  </div>\n  <div class='right'>\n";
},"3":function(container,depth0,helpers,partials,data) {
    return "  <div>\n";
},"5":function(container,depth0,helpers,partials,data) {
    return container.escapeExpression((helpers["topic-featured-link"] || (depth0 && depth0["topic-featured-link"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic",{"name":"topic-featured-link","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}));
},"7":function(container,depth0,helpers,partials,data) {
    return "&nbsp;<span class=\"badge-notification new-topic\"></span>";
},"9":function(container,depth0,helpers,partials,data) {
    return container.escapeExpression((helpers.raw || (depth0 && depth0.raw) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"list.topic-excerpt",{"name":"raw","hash":{"topic":"topic"},"hashTypes":{"topic":"PathExpression"},"hashContexts":{"topic":depth0},"types":["StringLiteral"],"contexts":[depth0],"data":data}));
},"11":function(container,depth0,helpers,partials,data) {
    return "        <div class='category'>\n          "
    + container.escapeExpression((helpers["category-link"] || (depth0 && depth0["category-link"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.category",{"name":"category-link","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\n        </div>\n";
},"compiler":[7,">= 4.0.0"],"main":function(container,depth0,helpers,partials,data) {
    var stack1;

  return "\n<td>"
    + ((stack1 = helpers.unless.call(depth0 != null ? depth0 : (container.nullContext || {}),"expandPinned",{"name":"unless","hash":{},"hashTypes":{},"hashContexts":{},"fn":container.program(1, data, 0),"inverse":container.program(3, data, 0),"types":["PathExpression"],"contexts":[depth0],"data":data})) != null ? stack1 : "")
    + "<div class='main-link'>"
    + container.escapeExpression((helpers["raw-plugin-outlet"] || (depth0 && depth0["raw-plugin-outlet"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),{"name":"raw-plugin-outlet","hash":{"name":"topic-list-before-status"},"hashTypes":{"name":"StringLiteral"},"hashContexts":{"name":depth0},"types":[],"contexts":[],"data":data}))
    + container.escapeExpression((helpers.raw || (depth0 && depth0.raw) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic-status",{"name":"raw","hash":{"topic":"topic"},"hashTypes":{"topic":"PathExpression"},"hashContexts":{"topic":depth0},"types":["StringLiteral"],"contexts":[depth0],"data":data}))
    + container.escapeExpression((helpers["topic-link"] || (depth0 && depth0["topic-link"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic",{"name":"topic-link","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + ((stack1 = helpers["if"].call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.featured_link",{"name":"if","hash":{},"hashTypes":{},"hashContexts":{},"fn":container.program(5, data, 0),"inverse":container.noop,"types":["PathExpression"],"contexts":[depth0],"data":data})) != null ? stack1 : "")
    + ((stack1 = helpers["if"].call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.unseen",{"name":"if","hash":{},"hashTypes":{},"hashContexts":{},"fn":container.program(7, data, 0),"inverse":container.noop,"types":["PathExpression"],"contexts":[depth0],"data":data})) != null ? stack1 : "")
    + ((stack1 = helpers["if"].call(depth0 != null ? depth0 : (container.nullContext || {}),"expandPinned",{"name":"if","hash":{},"hashTypes":{},"hashContexts":{},"fn":container.program(9, data, 0),"inverse":container.noop,"types":["PathExpression"],"contexts":[depth0],"data":data})) != null ? stack1 : "")
    + "</div>\n\n    <div class='pull-right'>\n      "
    + container.escapeExpression((helpers.raw || (depth0 && depth0.raw) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"list.post-count-or-badges",{"name":"raw","hash":{"postBadgesEnabled":"showTopicPostBadges","topic":"topic"},"hashTypes":{"postBadgesEnabled":"PathExpression","topic":"PathExpression"},"hashContexts":{"postBadgesEnabled":depth0,"topic":depth0},"types":["StringLiteral"],"contexts":[depth0],"data":data}))
    + "\n    </div>\n\n    <div class=\"topic-item-stats clearfix\">\n"
    + ((stack1 = helpers.unless.call(depth0 != null ? depth0 : (container.nullContext || {}),"hideCategory",{"name":"unless","hash":{},"hashTypes":{},"hashContexts":{},"fn":container.program(11, data, 0),"inverse":container.noop,"types":["PathExpression"],"contexts":[depth0],"data":data})) != null ? stack1 : "")
    + "\n      "
    + container.escapeExpression((helpers["discourse-tags"] || (depth0 && depth0["discourse-tags"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic",{"name":"discourse-tags","hash":{"mode":"list"},"hashTypes":{"mode":"StringLiteral"},"hashContexts":{"mode":depth0},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\n\n      <div class=\"pull-right\">\n        <div class='num activity last'>\n          <span class=\"age activity\" title=\""
    + container.escapeExpression(helpers.get.call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.bumpedAtTitle",{"name":"get","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\"><a href=\""
    + container.escapeExpression(helpers.get.call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.lastPostUrl",{"name":"get","hash":{},"hashTypes":{},"hashContexts":{},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "\">"
    + container.escapeExpression((helpers["format-date"] || (depth0 && depth0["format-date"]) || helpers.helperMissing).call(depth0 != null ? depth0 : (container.nullContext || {}),"topic.bumpedAt",{"name":"format-date","hash":{"noTitle":"true","format":"tiny"},"hashTypes":{"noTitle":"StringLiteral","format":"StringLiteral"},"hashContexts":{"noTitle":depth0,"format":depth0},"types":["PathExpression"],"contexts":[depth0],"data":data}))
    + "</a></span>\n        </div>\n      </div>\n\n      <div class=\"clearfix\"></div>\n    </div>\n  </div>\n</td>\n";
},"useData":true});
  }
})();
(function() {
  if ('Ember' in window) {
    Ember.TEMPLATES["components/latest-topic-list-item"] = Ember.HTMLBars.template({"id":null,"block":"{\"symbols\":[],\"statements\":[[0,\"\\n\"],[7,\"div\"],[11,\"class\",\"topic-poster\"],[9],[0,\"\\n\"],[4,\"user-link\",null,[[\"user\",\"class\",\"classNames\"],[[25,[\"topic\",\"lastPoster\"]],\"mobile-homepage-avatar\",[25,[\"topic\",\"lastPoster\",\"extraClasses\"]]]],{\"statements\":[[0,\"    \"],[1,[29,\"avatar\",[[25,[\"topic\",\"lastPoster\"]]],[[\"imageSize\"],[\"large\"]]],false],[0,\"\\n\"]],\"parameters\":[]},null],[10],[0,\"\\n\"],[7,\"div\"],[11,\"class\",\"main-link\"],[9],[0,\"\\n  \"],[7,\"div\"],[11,\"class\",\"top-row\"],[9],[0,\"\\n    \"],[1,[29,\"raw\",[\"topic-status\"],[[\"topic\"],[[25,[\"topic\"]]]]],false],[0,\"\\n    \"],[1,[29,\"topic-link\",[[25,[\"topic\"]]],null],false],[0,\"\\n\"],[4,\"if\",[[25,[\"topic\",\"featured_link\"]]],null,{\"statements\":[[0,\"      \"],[1,[29,\"topic-featured-link\",[[25,[\"topic\"]]],null],false],[0,\"\\n\"]],\"parameters\":[]},null],[0,\"    \"],[1,[29,\"topic-post-badges\",null,[[\"newPosts\",\"unseen\",\"url\"],[[25,[\"topic\",\"totalUnread\"]],[25,[\"topic\",\"unseen\"]],[25,[\"topic\",\"lastUnreadUrl\"]]]]],false],[0,\"\\n  \"],[10],[0,\"\\n  \"],[7,\"div\"],[11,\"class\",\"bottom-row\"],[9],[0,\"\\n    \"],[1,[29,\"category-link\",[[25,[\"topic\",\"category\"]]],null],false],[0,\"\\n    \"],[1,[29,\"discourse-tags\",[[25,[\"topic\"]]],[[\"mode\"],[\"list\"]]],false],[0,\"\\n  \"],[10],[0,\"\\n\"],[10],[0,\"\\n\"],[7,\"div\"],[11,\"class\",\"topic-stats\"],[9],[0,\"\\n  \"],[1,[29,\"raw\",[\"list/posts-count-column\"],[[\"topic\",\"tagName\"],[[25,[\"topic\"]],\"div\"]]],false],[0,\"\\n  \"],[7,\"div\"],[11,\"class\",\"topic-last-activity\"],[9],[0,\"\\n    \"],[7,\"a\"],[12,\"href\",[30,[[25,[\"topic\",\"lastPostUrl\"]]]]],[12,\"title\",[30,[[25,[\"topic\",\"bumpedAtTitle\"]]]]],[9],[1,[29,\"format-date\",[[25,[\"topic\",\"bumpedAt\"]]],[[\"format\",\"noTitle\"],[\"tiny\",\"true\"]]],false],[10],[0,\"\\n  \"],[10],[0,\"\\n\"],[10],[0,\"\\n\"]],\"hasEval\":false}","meta":{}});
  }
})();

Discourse.Topic.reopen({
  creator:function() {
    let poster = this.get('poster');
    let user;
    user = poster && poster.user;
    user.extraClasses = poster.extraClasses;
    return user;
  }.property("posters.firstObject"),    
  lastPoster:function() {
    let posters = this.get('posters');  
    let user;
    if (posters && posters.length > 0) {
      const latest = posters.filter(
        p => p.extras && p.extras.indexOf("latest") >= 0
      )[0];
      user = latest && latest.user;
      user.extraClasses = latest.extraClasses;
    }
    return user = user || this.get("creator");
  }.property("posters")
});

