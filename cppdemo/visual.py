import matplotlib.pyplot as plt
import numpy as np

high_confidence = [0.01,0.02,0.08,0.70,0.02,0.04,0.03,0.01,0.02,0.03,0.04,0.01,0,0.01,0.03,0]
low_confidence = [0.02,0.06,0.28,0.03,0.0,0.02,0.25,0.04,0.01,0.05,0.04,0.03,0.1,0.02,0.04,0.01]


size = 16
# 返回size个0-1的随机数

# x轴坐标, size=5, 返回[0, 1, 2, 3, 4]
x = np.arange(size)

# 有a/b/c三种类型的数据，n设置为3
total_width, n = 0.6, 2
# 每种类型的柱状图宽度
width = total_width / n

# 重新设置x轴的坐标
x = x - (total_width - width) / 2
print(x)

x_labels = ["a", "b", "c", "d", "e",
            'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p']
plt.ylim(0, 1)
plt.xticks(x, x_labels, rotation=-30, fontsize=12)
plt.tick_params(axis='x', width=0) # 隐藏刻度线
plt.tick_params(axis='y', width=0)

config = {
    "font.family": "Times New Roman", #'Times New Roman',  # 设置字体类型
}
plt.rcParams.update(config)

# 画柱状图
plt.bar(x, high_confidence, width=width, label="high_confidence in term of some metrics")
plt.bar(x + width, low_confidence, width=width, label="low_confidence in term of some metrics")



# 显示图例
plt.legend()
plt.title("")
plt.xlabel("")
plt.ylabel("")

plt.tight_layout()
plt.savefig("res.png")
