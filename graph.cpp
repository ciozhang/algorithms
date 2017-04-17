//图接口
template <typename Tv, typename Te> class Graph{ //顶点类型、边类型
private:
	void reset(){ //所有顶点、边的辅助信息复位
		for (int i = 0; i<n; i++){ //顶点
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
			parent(i) = -1; priority(i) = INT_MAX;
			for (int j = 0; j<n; i++) //边
				if (exists(i, j)) status(i, j) = UNDETERMINED;
		}
	}
public:/*...顶点操作、边操作、图算法：无论如何实现，接口必须统一..*/
}

//顶点和边
typedef enum{UNDISCOVERED, DISCOVERED, VISITED} VStatus;
template <typename Tv> struct Vertex{
	Tv data; int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	itn priority;
	Vertex( Tv const & d):
		data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
		dTime(-1),fTime(-1),                parent(-1),
		priority(INT_MAX){}

}

template<typename Tv, typename Te> class GraphMatrix: public Graph<Tv, Te>{
private:
	Vector< Vectex<Tv> > V; //顶点集
	Vertor< Vector< Edge<Te>* >> E; //边集
public:
	/*接口操作：顶点相关、边相关、...*/
	GraphMatrix(){ n = e = 0; } //构造
	~GraphMatrix(){ //析构
		for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			delete E[j][k]； //清除所有动态申请的边记录
	}
}