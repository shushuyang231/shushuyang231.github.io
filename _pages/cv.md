---
layout: archive
title: "CV"
permalink: /cv/
author_profile: true
redirect_from:
  - /resume
---

{% include base_path %}

<!-- ====== CV HEADER (visible on screen + print) ====== -->
<div class="cv-header" markdown="0">
  <h1 class="cv-name">{{ site.author.name }}</h1>
  <p class="cv-tagline">Incoming second-year undergraduate · LLM &amp; software-agent evaluation · interested in embodied intelligence &amp; robotics</p>
  <div class="cv-contact">
    <a href="mailto:{{ site.author.email }}"><i class="fas fa-envelope" aria-hidden="true"></i> {{ site.author.email }}</a>
    <span class="cv-sep">·</span>
    <a href="https://github.com/{{ site.author.github }}"><i class="fab fa-github" aria-hidden="true"></i> github.com/{{ site.author.github }}</a>
    <span class="cv-sep">·</span>
    <a href="{{ site.author.orcid }}"><i class="fas fa-id-card" aria-hidden="true"></i> ORCID</a>
    <span class="cv-sep">·</span>
    <span><i class="fas fa-map-marker-alt" aria-hidden="true"></i> {{ site.author.location }}</span>
  </div>
</div>

<!-- ====== SECTIONS ====== -->

Education | 教育背景
======
* B.Eng. in Engineering, Shanghai Jiao Tong University（上海交通大学）， 2025 – Present
  * Paris Elite Institute of Technology (SPEIT)（巴黎卓越工程师学院）
  * French engineering curriculum: mathematics, physics, and computer science

Areas of Interest | 兴趣领域
======
* Large language models（大语言模型）
* Embodied intelligence and robotics（具身智能与机器人学）
* Mechanical systems（机械）

Skills | 技能
======
* Python — basic working proficiency（具备基础实用能力）
* AI-native workflows — comfortable driving AI-assisted research and engineering workflows（AI 原生工作流）
* French — early B1（法语初级 B1 水平）
* English — CET-4, 646/710 (2025)（大学英语四级，646 分）

Projects | 项目
======
* [Ambiguous Tool Outcomes Benchmark](https://github.com/shushuyang231/ambiguous-tool-outcomes-benchmark) — counterfactual benchmark for LLM agent recovery from ambiguous tool outcomes
* [Side-Effect Calibration Study](https://github.com/shushuyang231/side-effect-calibration-study) — mutation testing of task-scoped state oracles in software-agent benchmarks
* [Schema Order Robustness](https://github.com/shushuyang231/schema-order-robustness) — reproducible study of JSON Schema serialization-order robustness in black-box LLM generation

Publications | 论文
======
<div class="cv-publications">
  {% for post in site.publications reversed %}
  <div class="cv-pub-item">
    <p class="cv-pub-title">
      <a href="{{ post.paperurl }}">{{ post.title }}</a>
    </p>
    <p class="cv-pub-meta">{{ post.venue }} · <a href="{{ post.paperurl }}">doi:{{ post.paperurl | remove: 'https://doi.org/' }}</a></p>
  </div>
  {% endfor %}
</div>

<!-- ====== EXPORT BUTTON ====== -->
<div class="cv-print-btn">
  <button onclick="window.print()" class="btn btn--primary">
    <i class="fas fa-file-pdf" aria-hidden="true"></i> Export as PDF
  </button>
</div>

<!-- ====== SCREEN + PRINT STYLES ====== -->
<style>
/* --- Screen styling for CV page --- */
.cv-header {
  text-align: center;
  border-bottom: 2px solid #7a8288;
  padding-bottom: 1em;
  margin-bottom: 1.5em;
}
.cv-header .cv-name {
  font-size: 2em;
  font-weight: 700;
  margin: 0 0 0.3em 0;
  letter-spacing: 0.02em;
}
.cv-header .cv-tagline {
  font-size: 0.9em;
  color: #6c7981;
  margin: 0 0 0.6em 0;
}
.cv-header .cv-contact {
  font-size: 0.85em;
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
  gap: 0.3em;
  align-items: center;
}
.cv-header .cv-contact a {
  color: inherit;
  text-decoration: none;
  white-space: nowrap;
}
.cv-header .cv-contact a:hover {
  text-decoration: underline;
}
.cv-sep {
  color: #bcc4cc;
}

.cv-publications .cv-pub-item {
  margin-bottom: 1em;
  padding-left: 1em;
  border-left: 3px solid #e0e4e8;
}
.cv-pub-title {
  margin: 0;
  font-weight: 600;
  line-height: 1.3;
}
.cv-pub-title a {
  color: #494e52;
}
.cv-pub-meta {
  margin: 0.2em 0 0 0;
  font-size: 0.85em;
  color: #7a8288;
}
.cv-pub-meta a {
  color: #7a8288;
  text-decoration: none;
}
.cv-pub-meta a:hover {
  text-decoration: underline;
}

.cv-print-btn {
  margin-top: 2.5em;
  text-align: center;
}

/* --- Print-only: professional resume layout --- */
@media print {
  /* Hide all site chrome */
  .masthead, .sidebar, .page__footer, .page__share,
  .page__related, .nav__list, .ads, .cv-print-btn,
  .greedy-nav, .sr-only, .breadcrumbs,
  #site-nav, .author__avatar, .author__urls-wrapper,
  .page__comments { display: none !important; }

  /* Reset layout */
  html, body {
    margin: 0 !important;
    padding: 0 !important;
    background: #fff !important;
    color: #000 !important;
    font-size: 11pt !important;
    line-height: 1.35 !important;
    font-family: "Helvetica Neue", "Arial", "PingFang SC", "Microsoft YaHei", sans-serif !important;
  }
  .page, #main {
    max-width: 100% !important;
    margin: 0 !important;
    padding: 0 !important;
  }

  /* CV header */
  .cv-header {
    text-align: center;
    border-bottom: 2px solid #333;
    padding-bottom: 0.6em;
    margin-bottom: 1.2em;
  }
  .cv-name {
    font-size: 20pt !important;
    margin: 0 0 0.2em 0 !important;
    letter-spacing: 0.03em;
  }
  .cv-tagline {
    font-size: 10pt !important;
    color: #444 !important;
    margin: 0 0 0.4em 0 !important;
  }
  .cv-contact {
    font-size: 9pt !important;
    justify-content: center !important;
  }
  .cv-contact a, .cv-contact span {
    color: #000 !important;
    text-decoration: none !important;
  }
  .cv-sep { color: #aaa !important; }

  /* Section headings */
  .page__content h2 {
    font-size: 13pt !important;
    text-transform: uppercase;
    letter-spacing: 0.08em;
    border-bottom: 1px solid #999;
    padding-bottom: 0.15em;
    margin-top: 1.4em !important;
    margin-bottom: 0.6em !important;
    page-break-after: avoid;
  }

  /* List items */
  .page__content ul {
    margin: 0 0 0.8em 0 !important;
    padding-left: 1.2em !important;
  }
  .page__content li {
    margin-bottom: 0.25em;
    page-break-inside: avoid;
  }

  /* Links: clickable but not decorated */
  a {
    color: #000 !important;
    text-decoration: none !important;
  }
  /* Show URLs for paper/project links in print margin */
  .cv-pub-title a[href]:after,
  .page__content li a[href]:after {
    content: "";
  }

  /* Publications */
  .cv-publications .cv-pub-item {
    margin-bottom: 0.7em !important;
    padding-left: 0.8em !important;
    border-left: 2px solid #ccc !important;
    page-break-inside: avoid;
  }
  .cv-pub-title {
    font-weight: 600 !important;
    font-size: 10.5pt !important;
  }
  .cv-pub-meta {
    font-size: 9pt !important;
    color: #555 !important;
  }
  .cv-pub-meta a { color: #555 !important; }

  /* Page setup */
  @page {
    margin: 1.5cm 2cm;
  }
}
</style>
