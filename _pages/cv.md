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
* Python（初级 / beginner level）

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
