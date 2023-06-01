import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

# CSV 파일 불러오기
df = pd.read_csv('outputs.csv')

# 그래프 객체 생성
G = nx.Graph()

# 엣지 추가
for index, row in df.iterrows():
    source = row['src']
    target = row['dst']
    weight = row['weights']
    G.add_edge(source, target, weight=weight)

# 그래프 그리기
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, font_size=5)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=5)
plt.show()