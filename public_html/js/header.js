/*
This script prepends the <header> tag into the body of whatever page it is
included in; this is basically an attempt at templating using jQuery.
This script also gives the navbar some custom styling that allows it to change
to fixed when the window scrolls down far enough.
*/

(function() {
  function defer(method) {
    if (window.jQuery)
       method(jQuery);
    else
      setTimeout(function() { defer(method); }, 50);
  }

  function main($) {
    $(document).ready(function() {
      $('body').prepend(
        '<header>' +
          '<div id="header">' +
            '<a href="./classpage.html">' +
              '<h2 class="header-text">Ohlone College | CS-175 | Fall 2015</h2>' +
            '</a>' +
            '<a href="https://www.linkedin.com/in/wolfgangcstrack">' +
              '<h2 class="header-text header-name">Wolfgang C. Strack</h2>' +
            '</a>' +
          '</div>' +
          '<div id="navbar">' +
            '<a class="nav-link" href="#">Home</a>' +
            '<a class="nav-link" href="#assignments">Assignments</a>' +
            '<a class="nav-link" href="#about">About</a>' +
            '<a class="nav-link" href="#contact">Contact</a>' +
          '</div>' +
        '</header>'
      );

      $(window).scroll(function(event) {
        var height = $(window).scrollTop();
        $nav = $('#navbar');
        if (height >= 100) {
          $nav.addClass('navbar-fixed-top');
        } else {
          $nav.removeClass('navbar-fixed-top');
        }
      });
    });
  }

  defer(main);
})();
