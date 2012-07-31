/***********************************************************************

Takes a list of points and returns a list of segments corresponding to the
Alpha shape.

************************************************************************/

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/algorithm.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Alpha_shape_2.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <list>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef K::FT FT;

typedef K::Point_2  Point;
typedef K::Segment_2  Segment;


typedef CGAL::Alpha_shape_vertex_base_2<K> Vb;
typedef CGAL::Alpha_shape_face_base_2<K>  Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> Triangulation_2;

typedef CGAL::Alpha_shape_2<Triangulation_2>  Alpha_shape_2;

typedef Alpha_shape_2::Face  Face;
typedef Alpha_shape_2::Vertex Vertex;
typedef Alpha_shape_2::Edge Edge;
typedef Alpha_shape_2::Face_handle  Face_handle;
typedef Alpha_shape_2::Vertex_handle Vertex_handle;

typedef Alpha_shape_2::Face_circulator  Face_circulator;
typedef Alpha_shape_2::Vertex_circulator  Vertex_circulator;

typedef Alpha_shape_2::Locate_type Locate_type;

typedef Alpha_shape_2::Face_iterator  Face_iterator;
typedef Alpha_shape_2::Vertex_iterator  Vertex_iterator;
typedef Alpha_shape_2::Edge_iterator  Edge_iterator;
typedef Alpha_shape_2::Edge_circulator  Edge_circulator;

typedef Alpha_shape_2::Alpha_iterator Alpha_iterator;
typedef Alpha_shape_2::Alpha_shape_edges_iterator Alpha_shape_edges_iterator;
typedef Alpha_shape_2::Alpha_shape_vertices_iterator Alpha_shape_vertices_iterator;

//---------------------------------------------------------------------

template <class OutputIterator>
void
alpha_edges( const Alpha_shape_2&  A,
	     OutputIterator out)
{

  for(Alpha_shape_edges_iterator it =  A.alpha_shape_edges_begin();
      it != A.alpha_shape_edges_end();
      ++it){
      *out++ = A.segment(*it);
  }
}

template <class OutputIterator>
void
alpha_vertices( const Alpha_shape_2&  A,
	     OutputIterator out)
{

  for(Alpha_shape_vertices_iterator it =  A.alpha_shape_vertices_begin();
      it != A.alpha_shape_vertices_end();
      ++it){
      *out++ = Vertex_handle(*it);
  }
}

template <class OutputIterator>
bool
file_input(OutputIterator out)
{
  std::ifstream is("./data/fin", std::ios::in);

  if(is.fail()){
    std::cerr << "unable to open file for input" << std::endl;
    return false;
  }

  int n;
  is >> n;
  //std::cout << "Reading " << n << " points from file" << std::endl;
  CGAL::copy_n(std::istream_iterator<Point>(is), n, out);

  return true;
}

//------------------ functions --------------------------------------

/**
  This function tries to obtain an ordered list of the segments to form a polygon
*/
void toWKT_polygon(std::vector<Segment> segments, const Alpha_shape_2& A){

  for(std::vector<Segment>::iterator it = segments.begin(); it != segments.end();++it){
  
  }
}

void toWKT_segments(std::vector<Segment> segments, const Alpha_shape_2& A){

  std::cout << "id;wkt" << std::endl;
  int count = 0;

  for(std::vector<Segment>::iterator it = segments.begin(); it != segments.end();++it){
    std::cout << count << ";" << "LINESTRING(" << it->source() << "," << it->target() << ") " << std::endl;
    count++;
  }
  
}

void toWKT_vertices(std::vector<Vertex_handle> segments, const Alpha_shape_2& A){
  int count = 0; 
  
  std::cout << "id;wkt" << std::endl;
  for(std::vector<Vertex_handle>::iterator it = segments.begin(); it != segments.end();++it){
    Point p=(*it)->point();
    std::cout << count << ";" << "POINT(" << p[0] << " " << p[1] << ")" << std::endl;
    count++;
  }

  
}
//------------------ main -------------------------------------------

int main(int argc, char* argv[])
{
  //output the points as CSV WKT
  bool bpoints = false;
  for(int i = 0; i < argc; i++){
    if (strcmp(argv[i],"-p")) {
        bpoints = true;
    }
  }

    std::cout << bpoints << std::endl;

  std::list<Point> points;

  if(! file_input(std::back_inserter(points))){
    return -1;
  }

  Alpha_shape_2 A(points.begin(), points.end());
  Alpha_iterator opt = A.find_optimal_alpha(1);
  A.set_alpha(*opt);
  //A.set_alpha(1);
  A.set_mode(Alpha_shape_2::GENERAL);
  
  std::vector<Segment> segments;
  std::vector<Vertex_handle> vertices;

  alpha_edges( A, std::back_inserter(segments));
  alpha_vertices( A, std::back_inserter(vertices));

  //std::cout << "Alpha Shape computed" << std::endl;
  //std::cout << segments.size() << " alpha shape edges" << std::endl;
  //std::cout << "Optimal alpha: " << *A.find_optimal_alpha(1) <<std::endl;

  //print result
  if (bpoints){
    toWKT_vertices(vertices,A);
  }
  else{
    toWKT_segments(segments,A);
  }
  return 0;
}