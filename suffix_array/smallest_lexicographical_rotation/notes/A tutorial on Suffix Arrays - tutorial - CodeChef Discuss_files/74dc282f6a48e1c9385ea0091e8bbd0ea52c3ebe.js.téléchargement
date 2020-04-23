
  Discourse.ExternalNavItem = Discourse.NavItem.extend({
    href : function() {
      return this.get('href');
    }.property('href')
  });

  I18n.translations.en.js.filters.unanswered = { title: "Unanswered", help: "Topics that have not be answered" };

  Discourse.NavItem.reopenClass({
    buildList : function(category, args) {
      var list = this._super(category, args);
      if(!category) {
        list.push(Discourse.ExternalNavItem.create({href: '/latest?max_posts=1', name: 'unanswered', class: 'active'}));
      }
      return list;
    }
  });

