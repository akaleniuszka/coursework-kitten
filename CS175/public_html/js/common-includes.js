/*
This script takes away the repetitiveness of copy/pasting common link and
script tags (considering this class is not about using a dynamic backend
language like Python or PHP).
*/

function defer_jQuery(method) {
  if (window.jQuery)
     method(jQuery);
  else
    setTimeout(function() { defer_jQuery(method); }, 50);
}

(function() {
  var cssURLs = [
    // local
    'http://toolkit.cs.ohlone.edu/~gen246/css/theme.css',
    'http://toolkit.cs.ohlone.edu/~gen246/css/bootstrap-social.css',
    // remote
    'https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css',
    'https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css'
  ];

  var jsURLs = [
    // local
    'http://toolkit.cs.ohlone.edu/~gen246/js/header.js',
    'http://toolkit.cs.ohlone.edu/~gen246/js/footer.js',
    // remote
    'https://code.jquery.com/jquery-2.1.4.min.js'
  ];

  var loadCSS = function(url) {
    var stylesheet = document.createElement('link');
    stylesheet.href = url;
    stylesheet.rel = 'stylesheet';
    stylesheet.type = 'text/css';
    document.getElementsByTagName('head')[0].appendChild(stylesheet);
  };

  var loadJS = function(url) {
    var script = document.createElement('script');
    script.src = url;
    script.type = 'text/javascript';
    script.charset = 'utf-8';
    script.defer = true;
    document.head.appendChild(script);
  };

  cssURLs.forEach(function(url) { loadCSS(url); });
  jsURLs.forEach(function(url) { loadJS(url); });
})();
