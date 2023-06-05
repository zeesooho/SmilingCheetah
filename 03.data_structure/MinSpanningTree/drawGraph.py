import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

# CSV 파일 불러오기
df = pd.read_csv('outputs2.csv')

# 그래프 객체 생성
G = nx.Graph()

# 엣지 추가
for index, row in df.iterrows():
    source = row['src']
    target = row['dst']
    weight = row['weights']
    G.add_edge(source, target, weight=weight)

# 그래프 그리기
pos = nx.spring_layout(G)  # k 값을 조정하여 노드 간격을 조절
plt.figure(figsize=(10, 10))  # 그래프 크기 조정
nx.draw(G, pos, with_labels=True, font_size=10, node_size=300)  # 노드 크기 조정
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=10)
plt.show()