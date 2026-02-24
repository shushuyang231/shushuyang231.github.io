<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>文件下载页面</title>
    
    <style>
        /* 设置整个页面的基础样式 */
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; /* 设置字体 */
            display: flex;            /* 开启弹性盒布局，为了让内容居中 */
            justify-content: center;  /* 水平居中 */
            align-items: center;      /* 垂直居中 */
            height: 100vh;            /* 让页面的高度占满整个屏幕 */
            background-color: #f0f2f5;/* 设置一个淡淡的浅灰色背景 */
            margin: 0;                /* 移除浏览器默认的页面边距 */
        }

        /* 设置中间白色卡片的样式 */
        .download-card {
            background-color: white;  /* 卡片背景为白色 */
            padding: 40px 60px;       /* 卡片内部的留白 */
            border-radius: 12px;      /* 让卡片的四个角变得圆润 */
            box-shadow: 0 8px 16px rgba(0,0,0,0.1); /* 添加一点淡淡的阴影，增加立体感 */
            text-align: center;       /* 让卡片里的文字居中 */
        }

        /* 美化下载按钮 */
        .download-button {
            display: inline-block;    /* 让它既像按钮又能设置宽高 */
            margin-top: 20px;         /* 按钮顶部留出一点空间 */
            padding: 12px 24px;       /* 按钮内部的留白，控制按钮大小 */
            background-color: #0078d4;/* 按钮的主色调（蓝色） */
            color: white;             /* 按钮文字为白色 */
            text-decoration: none;    /* 去掉链接自带的下划线 */
            font-size: 16px;          /* 字体大小 */
            font-weight: bold;        /* 字体加粗 */
            border-radius: 6px;       /* 按钮的边角也变圆润 */
            transition: background-color 0.3s ease; /* 鼠标放上去时的颜色渐变动画 */
        }

        /* 鼠标悬停在按钮上时的效果 */
        .download-button:hover {
            background-color: #005a9e;/* 颜色变深一点，提供互动反馈 */
        }
    </style>
</head>
<body>

    <div class="download-card">
        <h2>应用程序下载</h2>
        <p>点击下方的按钮即可获取 <strong>authenticat.apk</strong> 文件。</p>
        
        <a href="https://shushuyang231.github.io/files/authenticat.apk" class="download-button" download="authenticat.apk">
            📥 下载 APK 文件
        </a>
    </div>

</body>
</html>
