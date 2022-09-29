const toCamel = (str: string) => {
  return str.replace(/([-_][a-z])/gi, (key) => {
    return key.toUpperCase().replace('-', '').replace('_', '');
  });
};

const isObject = (obj: any) => {
  return obj === Object(obj) && !Array.isArray(obj) && typeof obj !== 'function';
};

export const keysToCamel = (obj: any): any => {
  if (isObject(obj)) {
    const n: any = {};

    Object.keys(obj).forEach((k: string) => {
      n[toCamel(k)] = keysToCamel(obj[k]);
    });

    return n;
  } else if (Array.isArray(obj)) {
    return obj.map((i) => {
      return keysToCamel(i);
    });
  }
  return obj;
};
