export class Polygon{
    points = [];
    addPoint(p){
        this.points.push(p);
        //this.sortPoints();
    }
    sortPoints(){
        let my = 0;
        let mX = 0;
        for(let p of this.points){
            mX += p.x;
            my += p.y;
        }
        mX /= this.points.length;
        my /= this.points.length;
        this.points = this.points.sort((a,b) => Math.atan2(b.y - my, b.x - mX) - Math.atan2(a.y - my, a.x - mX));
    }
    deletePoint(p){
        this.points.splice(this.points.indexOf(p),1);
    }
    pointCheck(){

    }
    getIntersectPolygon(){

    }
}