/*
-------------------------------------------------------------------------
NAME: Divyen K Patel			Roll No :24					MCA: 4

Scanfill
-------------------------------------------------------------------------
*/

# include <dos.h>
# include <stdio.h>
# include <graphics.h>
# include <iostream.h>
# include <conio.h>
# include <math.h>

struct Polygon
{
	int x;
	int y;
};

struct edRecord
{
	int YUpper;
	float XIntersect;
	float dxperscan;
	struct edRecord *Next;
};

typedef struct edRecord Edge;
typedef struct Polygon Nodes;
Edge  *Active;
Edge **Edges;
int Cntr=6;
Nodes NodesObj[6]={{100,100},{150,150},{150,200},{100,250},{50,200},{50,150}};

void Scanfill();
void InsertEdge(Edge*,Edge*);
void BuildEdgeList(int,Nodes*);
int YNext(int);
void MakeEdgeRec(Nodes,Nodes,int,Edge*);
void BulidActiveList(int);
void UpdateActiveList(int);
void DeleteAfter(Edge*);
void ResortActiveList(void);
void ResortActiveList(int);

//**************************************************************************
void main()
{
	int gDriver = DETECT, gMode;
	int n,xArray[12];
	int iCntr,jCntr;

	initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
		
	for(iCntr=0,jCntr=0;iCntr<12;iCntr+=2,jCntr++)
		xArray[iCntr] = NodesObj[jCntr].x;
	for(iCntr=1,jCntr=0;iCntr<12;iCntr+=2,jCntr++)
		xArray[iCntr] = NodesObj[jCntr].y;
	
	drawpoly(6,xArray);
	
	line(NodesObj[5].x,NodesObj[5].y,NodesObj[0].x,NodesObj[0].y);   //TO CLOSE POLYGON
	getch();
	
	Scanfill();
	getch();
	closegraph();
	restorecrtmode();
	return;
}

//**************************************************************************

void Scanfill()
{
	int iCntr,Scan;
	//initialize edgelists with dummy nodes
	Edges=new Edge*[getmaxy()];
	for(iCntr=0;iCntr<getmaxy();iCntr++)
	{
		Edges[iCntr] = new Edge;
		Edges[iCntr]->Next = NULL;
	}
	//initialize Active edgeList with dummy nodes
	Active = new Edge;
	Active->Next = NULL;
	BuildEdgeList(Cntr,NodesObj);
	for(Scan=0;Scan<getmaxy();Scan++)
	{
		BulidActiveList(Scan);
		if (Active->Next != NULL)
		{
			ResortActiveList(Scan);
			UpdateActiveList(Scan);
			ResortActiveList();
		}
	}
}

//**************************************************************************

void InsertEdge(Edge* edgeList,Edge* InitialEdge)
{
	Edge *PEdge,*QEdges;

	QEdges=edgeList;
	PEdge=QEdges->Next;
	while(PEdge!=NULL)
	if(InitialEdge->XIntersect < PEdge->XIntersect)
	PEdge=NULL;
	else
	{
		QEdges=PEdge;
		PEdge=PEdge->Next;
	}
	InitialEdge->Next = QEdges->Next;
	QEdges->Next = InitialEdge;
}

//**************************************************************************

void BuildEdgeList(int Cntr,Nodes* Vertices)
{
	Edge* NewEdge;
	Nodes Vertex1,Vertex2;
	int YPrev,iCntr;
	Vertex1.x=Vertices[Cntr-1].x;
	Vertex1.y=Vertices[Cntr-1].y;
	YPrev = Vertices[Cntr-2].y;
	for(iCntr=0;iCntr<Cntr;iCntr++)
	{
		Vertex2.x = Vertices[iCntr].x;
		Vertex2.y = Vertices[iCntr].y;
		if(Vertex1.y != Vertex2.y)
		{
			NewEdge = new Edge;
			if(Vertex1.y < Vertex2.y)
				MakeEdgeRec(Vertex1,Vertex2,YNext(iCntr),NewEdge);
			else
				MakeEdgeRec(Vertex2,Vertex1,YPrev,NewEdge);
		}
		YPrev = Vertex1.y;
		Vertex1.x = Vertex2.x;
		Vertex1.y = Vertex2.y;
	}
}

//**************************************************************************

void BulidActiveList(int Scan)
{
	Edge *PEdge,*QEdges;
	PEdge=Edges[Scan]->Next;
	while(PEdge!=NULL)
	{
		QEdges=PEdge->Next;
		InsertEdge(Active,PEdge);
		PEdge=QEdges;
	}
}

//***************************************************************************

void ResortActiveList(int Scan)
{
	Edge *iEdge,*jEdge;
	int iCntr;
	iEdge = Active->Next;
	while(iEdge!=NULL)
	{
		jEdge = iEdge->Next;
		for(iCntr=iEdge->XIntersect;iCntr<=jEdge->XIntersect-1;iCntr++)
			putpixel(iCntr,Scan,RED);
		iEdge=jEdge->Next;
	}
}
//***************************************************************************

void UpdateActiveList(int Scan)
{
	Edge *PEdge,*QEdges;
	QEdges=Active;
	PEdge=Active->Next;
	while(PEdge!=NULL)
	{
		if(Scan>=PEdge->YUpper)
		{
			PEdge=PEdge->Next;
			DeleteAfter(QEdges);
		}
		else
		{
			PEdge->XIntersect+=PEdge->dxperscan;
			QEdges=PEdge;
			PEdge=PEdge->Next;
		}
	}
}
//***************************************************************************
void ResortActiveList()
{
	Edge *PEdge,*QEdges;
	PEdge=Active->Next;
	Active->Next=NULL;
	while(PEdge!=NULL)
	{
		QEdges=PEdge->Next;
		InsertEdge(Active,PEdge);
		PEdge=QEdges;
	}
}

//***************************************************************************

int YNext(int YCurr)
{
	int jCntr;
	if(YCurr+1>Cntr)
		jCntr=1;
	else
		jCntr=YCurr+1;
	while(NodesObj[YCurr].y == NodesObj[jCntr].y)
	{
		if(jCntr+1>Cntr)
			jCntr=1;
		else
			jCntr++;
	}
	return(NodesObj[jCntr].y);
}

//***************************************************************************

void DeleteAfter(Edge* QEdges)
{
	Edge* PEdge;

	PEdge = QEdges->Next;
	QEdges->Next = PEdge->Next;
	delete PEdge;
}

//***************************************************************************

void MakeEdgeRec(Nodes Lower,Nodes Upper,int YComp,Edge* CurrEdge)
{
	CurrEdge->dxperscan = (Upper.x - Lower.x) / (Upper.y - Lower.y);
	CurrEdge->XIntersect = Lower.x;
	if(Upper.y < YComp)
		CurrEdge->YUpper = Upper.y - 1;
	else
		CurrEdge->YUpper = Upper.y;
	InsertEdge(Edges[Lower.y],CurrEdge);
}
