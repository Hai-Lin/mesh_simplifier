/*
 * =====================================================================================
 *
 *       Filename:  Mesh.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 01:25:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Mesh.h"

void StringSplit(string str, string separator, vector<string>* results){
	int found;
	found = str.find_first_of(separator);
	while(found != string::npos){
		if(found > 0){
			results->push_back(str.substr(0,found));
		}
		str = str.substr(found+1);
		found = str.find_first_of(separator);
	}
	if(str.length() > 0){
		results->push_back(str);
	}
}

void Mesh::setFaceNormal()
{
	Vector3D edge1, edge2,normal;
	for(unsigned int i=0; i<triangles.size();++i)
	{
		edge1=vertices[triangles[i].ver_id[1]].point-vertices[triangles[i].ver_id[0]].point;
		edge2=vertices[triangles[i].ver_id[2]].point-vertices[triangles[i].ver_id[1]].point;
		normal=edge1*edge2;
		triangles[i].faceNormal=normalize(normal);
		triangles[i].isNormal=true;
		/*  
		vertices[triangles[i].ver_id[0]].point.display();
		vertices[triangles[i].ver_id[1]].point.display();
		vertices[triangles[i].ver_id[2]].point.display();
		edge1.display();
		edge2.display();
		normal.display();
		*/

	}
}
void Triangle::displayTriangle()
{
	cout<<"Triangle id: "<<id<<endl;
	cout<<"Triangle vertices id: ";
	for(int i=0; i<=2;++i)
		cout<<i<<" : "<<ver_id[i]<<" ";
	cout<<endl;
	if(isNbr)
	{
		cout<<"Triangle nerbighor's id are: "<<endl;
		for(int i=0; i<=2;++i)
		{
			cout<<i<<" : "<<nbr_id[i]<<" ";
		}
	}
	else
	{
		cout<<"Triangle neibhor is not avaliable now"<<endl;
	}
	cout<<endl;
	if(isNormal)
	{
		cout<<"Triangle's normal is:"<<endl;
		faceNormal.display();
	}
	else
	{
		cout<<"Triangle's normal is not avaiable now"<<endl;
	}



}
void Vertex::displayVertex()
{
	cout<<"Vertex id: "<<id<<endl;
	cout<<"Vertex point:";
	point.display();
	for(int i=0; i<=3;++i)
	{
		if(isNormal[i])
		{
			cout<<"Vertex's "<<i<<"'s normal is:"<<endl;
			normal[i].display();

		}
		else
			cout<<"Normal "<<i<<" is not avaiable"<<endl;

	}

}



void Mesh::loadFile( char* fileName)
{
	ifstream input(fileName);
	string line;
	vector<string> temp;
	if(input.is_open())
	{
		cout<<"file opens successfully"<<endl;


		while(getline(input,line))
		{
			temp.clear();
			StringSplit(line," ",&temp);
			if(temp[0]=="#")
				continue;
			if(temp[0]=="v")
			{
				if(temp.size()==4)
				{
					Vertex tempVertex(atof(temp[1].c_str()),atof(temp[2].c_str()),atof(temp[3].c_str()),vertices.size());
					vertices.push_back(tempVertex);
				}
				else
				{
					cout<<"file format error: v size"<<endl;
				}

			}
			if(temp[0]=="f")
			{
				if(temp.size()==4)
				{
					Triangle tempTriangle(atoi(temp[1].c_str())-1,atoi(temp[2].c_str())-1,atoi(temp[3].c_str())-1,triangles.size());
					triangles.push_back(tempTriangle);
				}
				else
				{
					cout<<"file format error: v size"<<endl;
				}

			}

		}
		cout<<"succefully load "<<vertices.size()<<" vertices and "<<triangles.size()<<" triangles"<<endl;
	}
	else
	{
		cout<<"file open error"<<endl;
	}
}

void Mesh::displayMesh()
{
	cout<<"This is vertics:"<<endl;
	for(unsigned int i =0; i<vertices.size(); ++i)
		vertices[i].displayVertex();
	cout<<"This is trangles:"<<endl;
	for(unsigned int i=0; i<triangles.size();++i)
		triangles[i].displayTriangle();

}
/*  
int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		cout<<"invalid input!"<<endl;
		return -1;
	}

	Mesh myMesh;
	myMesh.loadFile(argv[1]);
	myMesh.setFaceNormal();
	myMesh.displayMesh();

	return 0;
}


*/
