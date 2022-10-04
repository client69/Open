int modexp(ll v,int k)
{
	// res = v**k %MOD;
	ll res=1;
	while(k>0)
	{
		if(k&1)
			res=(res*v)%MOD;
		k>>=1;
		v=(v*v)%MOD;
	}
	return res;
}