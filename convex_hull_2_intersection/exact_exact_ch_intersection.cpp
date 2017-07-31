#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <CGAL/Polygon_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef CGAL::Polygon_2<K> Polygon_2;
typedef K::Point_2 Point_2;
typedef K::Ray_2 Ray_2;
typedef K::Segment_2 Segment_2;
typedef K::Intersect_2 Intersect_2;
typedef Polygon_2::Edge_const_iterator EdgeIterator;

typedef std::vector<Point_2> Points;

int main() {

  Points points, result;

  Polygon_2 chP;

  points.push_back( Point_2( -10, -10 ) );
  points.push_back( Point_2(  10, -10 ) );
  points.push_back( Point_2(  10,  10 ) );
  points.push_back( Point_2( -10,  10 ) );

  CGAL::convex_hull_2( points.begin(), points.end(), std::back_inserter(chP) );
  std::cout << chP.size() << " vertices on the convex hull" << std::endl;

  Ray_2 ray = Ray_2( Point_2( 0, 0 ), Point_2( 0, 1) );

  for( EdgeIterator it = chP.edges_begin(); it != chP.edges_end(); ++it) {
    CGAL::cpp11::result_of<Intersect_2(Segment_2, Ray_2)>::type
      result = intersection(*it, ray);
    if (result) {
      if (const Segment_2* s = boost::get<Segment_2>(&*result)) {
        std::cout << *s << std::endl;
      } else {
        const Point_2* p = boost::get<Point_2 >(&*result);
        std::cout << "segment " << *it << " intersected at " << *p << std::endl;
      }
    }
  }

  return 0;
}
