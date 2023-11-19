export class Point
{
    label;
    data;
    edges = [];
    constructor(props){
        this.label = props.label ?? "";
        this.data = props.data;
    }
}

export class Edge{
    label;
    data;
    constructor(props){
        this.label = props.label ?? "";
        this.data = props.data ?? {};
    }
}

export class Graph{

    points = new Map();

    addPoint(point) {
        this.points.set(point.label, point);
    }

    /**
     * @param {Point} p1 
     * @param {Point} p2 
     */
    addEdge(p1, p2) {
        p1.edges.push(p2);
        p2.edges.push(p1);
    }
    /**
     * @param {Point} p1 
     * @param {Point} p2 
     */
    removeEdge(p1, p2){
        p1.edges.find((p)=>p.connections)
        p2.edges.find((p)=>p.connections)
    }
}



/**
 * Trees have a node, which can have none, 1 or 2 nodes. Specific cases allow 3 or more.
 * Nodes must have only 2 edges (parent, child);
 */
export class Tree{

    instance = new Graph();

    getPoint(label){

    }
    addChild(){
        
    }
    removeChild(point){

    }
}





let pa = new Point({label: "pointFirst", data:{title:"Harry Potter"}});
let pb = new Point({label: "point Second", data:{title:"Hunger Games"}});
let pc = new Point({label: "point Final", data:{title:"Twitter"}});
let pd = new Point({label: "point Amazonas", data:{title:"Amazon"}});

let G = new Graph()
let T = new Tree();

G.addPoint(pa)
G.addPoint(pb)
G.addPoint(pc)
G.addPoint(pd)

G.addEdge(pa, pb);
G.addEdge(pa, pc);

G.addEdge(pd, pa);
G.addEdge(pd, pb);
G.addEdge(pd, pc);

console.log(pa);
console.log(pd);


