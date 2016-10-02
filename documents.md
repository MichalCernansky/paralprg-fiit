---
layout: page
title: Prednášky
---

{% for category in site.data.documents %}

## {{ category.name }}

{% for document in category.items %}

- [{{ document.name }}]({{ site.baseurl }}\documents\{{ document.url }})  

{% endfor %}

{% endfor %}
