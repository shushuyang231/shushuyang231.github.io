---
layout: archive
title: "CV"
permalink: /cv/
author_profile: true
redirect_from:
  - /resume
---

{% include base_path %}

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
  <ul>{% for post in site.publications reversed %}
    {% include archive-single-cv.html %}
  {% endfor %}</ul>

<div class="cv-print-btn" style="margin-top:2em;">
  <button onclick="window.print()" class="btn btn--primary">
    <i class="fa fa-print" aria-hidden="true"></i> Print / Export PDF
  </button>
</div>

<style>
@media print {
  .masthead, .sidebar, .page__footer, .page__share,
  .page__related, .nav__list, .ads, .cv-print-btn,
  .greedy-nav, .sr-only { display: none !important; }
  .page { margin: 0 !important; padding: 0 !important; }
  #main { max-width: 100% !important; margin: 0 !important; padding: 0 !important; }
  body { font-size: 12pt; line-height: 1.4; color: #000; background: #fff; }
  a { color: #000; text-decoration: none; }
  a[href]:after { content: ""; }
  h2 { page-break-after: avoid; }
  ul, ol { page-break-inside: avoid; }
}
</style>
