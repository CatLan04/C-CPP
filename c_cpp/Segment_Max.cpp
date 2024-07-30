struct Segment_Max{
	struct node{
		int l,r;
		ll val,lz;
	};
	int n;
	vector<node>tree;
	void build(int l,int r,int vt = 1){
		tree[vt].val = tree[vt].lz = 0;
		if( ( tree[vt].l = l ) == ( tree[vt].r = r ) )return;
		int mid = (l+r)>>1;
		build(l,mid,vt<<1);
		build(mid+1,r,vt<<1|1);
	}
	void init(int _n){
		n = _n;
		tree.resize(4*n+1);
		build(1,n);
	}
	void down(int vt){
		tree[vt<<1].val += tree[vt].lz;
		tree[vt<<1|1].val += tree[vt].lz;
		tree[vt<<1].lz += tree[vt].lz;
		tree[vt<<1|1].lz += tree[vt].lz;
		tree[vt].lz = 0;
	}
	void upd(int ql,int qr,ll val,int vt = 1 ){
		if(tree[vt].l > qr || ql > tree[vt].r)return;
		if(ql <= tree[vt].l && tree[vt].r <= qr){
			tree[vt].val += val;
			tree[vt].lz += val;
			return;
		}
		down(vt);
		upd(ql,qr,val,vt<<1);
		upd(ql,qr,val,vt<<1|1);
		tree[vt].val = max(tree[vt<<1].val,tree[vt<<1|1].val);
	}
	ll get(int ql,int qr,int vt = 1){
		if(tree[vt].l > qr || tree[vt].r < ql)return -inf;
		if(ql <= tree[vt].l && tree[vt].r <= qr)return tree[vt].val;
		down(vt);
		return max(get(ql,qr,vt<<1) , get(ql,qr,vt<<1|1));
	}
};